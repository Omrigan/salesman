#include <algorithm>
#include <assert.h>
#include <chrono>
#include <functional>
#include <iostream>
#include <iterator>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// TODO: unify variables namestyle
// TODO: use better random

using Clock = chrono::steady_clock;
using Microseconds = chrono::microseconds;
using Time = Clock::time_point;

static constexpr int MAX_AIRPORT = 300 + 12;
static constexpr int RESHUFFLE_ATTEMPTS = 112;
static constexpr int MAX_ATTEMPT = 112;


struct Edge;

struct Airport {
    int idx, zone;
    int local_idx;
    vector<Edge*> edges_from;
};

struct Edge {
    Airport* from;
    Airport* to;
    int day, cost;

    bool operator < (const Edge& other) const {
        return cost < other.cost;
    }
};

struct Assignment {
    Time start_time = Clock::now(), 
    finish_time;
    int kind = -1; // 0 - small, 1 - medium, 2 - large
    int N;
    Airport* start;
    vector<Airport> airports;
    vector<Edge> edges; 
    unordered_map<string, int> airport_name_to_idx;
    vector<string> idx_to_airport;
    vector<string> zones;
    vector<vector<const Airport*>> zone_airports;
    int max_edge_cost = -1;

    void init() {
        for (int i = 0; i < edges.size(); ++i) {
            edges[i].from->edges_from.push_back(&edges[i]);
        }

        if (N <= 20) { 
            kind = 1;
            finish_time = start_time + std::chrono::milliseconds(2700);
        } else if (N <= 100) {
            kind = 2;
            finish_time = start_time + std::chrono::milliseconds(4700);
        } else {
            kind = 3;
            finish_time = start_time + std::chrono::milliseconds(14700);
        }
    }

    bool ready_to_stop() {
        return Clock::now() > finish_time;
    }
};

struct Solution {
    const Assignment* task;
    vector<const Edge*> sequence;
    int total_score = 0;
    bool correct = false;

    void score() {
        total_score = 0;
        if (task != nullptr) {
            correct = sequence.size() == task->N;
            if (!correct) {
                return;
            }
            for(const Edge* x : sequence) {
                total_score += x->cost;
            }
        }
    }

    void print() {
        cout << total_score << endl;
        for(int i = 0; i < sequence.size(); ++i) {
            const Edge* e = sequence[i];
            cout << task->idx_to_airport[e->from->idx] << " " << task->idx_to_airport[e->to->idx] << " "
                 << i + 1 << " " << e->cost << endl;
        }
    }

};

Solution solve_simple(Assignment* task) {
    Solution sol{ .task = task };
    Airport* current_place = task->start;
    vector<bool> visited(task->N);
    visited[current_place->zone] = true;
    for(int current_day = 0; current_day < task->N; ++current_day) {
        int limit = current_place->edges_from.size(), 
            offset = rand() % limit;
        if(current_day == task->N - 1) {
            visited[task->start->zone] = false;
        }
        for(int i = 0; i < limit; ++i) {
            int idx = (i + offset) % limit;
            Edge* e = current_place->edges_from[idx];
            if (!visited[e->to->zone] and (e->day == -1 or e->day == current_day)) {
                sol.sequence.push_back(e);
                current_place = e->to;
                visited[current_place->zone] = true; 
                break;
            }
        }
    }
    sol.score();
    return sol;
}

vector<int> get_zone_order(const Assignment* task) {
    vector<int> zone_order;
    for (int i = 0; i < task->N; ++i) {
        if (i != task->start->zone) zone_order.push_back(i);
    }
    random_shuffle(zone_order.begin(), zone_order.end());
    zone_order.push_back(task->start->zone);
    return zone_order;
}

int max_size(const vector<vector<const Airport*>>& v) {
    int max_size = 0;
    for (const vector<const Airport*> a : v) {
        if (max_size < a.size()) max_size = a.size();
    }
    return max_size;
}

Solution dp_construct_solution_from(const Assignment* task, const vector<vector<const Edge*>> dp_restore) {
    Solution solution;
    solution.task = task;

    int local_idx = task->start->local_idx;
    int day = task->N - 1;
    while (day >= 0) {
        const Edge* cur_edge = dp_restore[day][local_idx];
        solution.sequence.push_back(cur_edge);
        local_idx = cur_edge->from->local_idx;
        --day;
    }
    reverse(solution.sequence.begin(), solution.sequence.end());
    return solution;
}

// for debug purposes only
static int max_day = 0;

void recalc_dp(const Assignment* task, 
               vector<vector<int>>& best_distance,
               vector<vector<const Edge*>>& dp_restore, 
               const int prev_zone,
               const int zone,
               const int day,
               bool& made_relaxation) {
    for (int airport_idx = 0; airport_idx < task->zone_airports[prev_zone].size(); ++airport_idx) {
        if (best_distance[0][airport_idx] != -1) {
            const Airport* prev_airport = task->zone_airports[prev_zone][airport_idx];
            for (const Edge* edge : prev_airport->edges_from) {
                if ((task->max_edge_cost == -1 or edge->cost <= task->max_edge_cost) and
                    (edge->day == day or edge->day == -1) and
                    edge->to->zone == zone and
                    (best_distance[1][edge->to->local_idx] == -1 or
                    best_distance[1][edge->to->local_idx] > best_distance[0][edge->from->local_idx] + edge->cost)) {
                    best_distance[1][edge->to->local_idx] = best_distance[0][edge->from->local_idx] + edge->cost;
                    dp_restore[day][edge->to->local_idx] = edge;
                    made_relaxation = true;
                }
            }
        }
    }
}

Solution fixed_zone_order_dp(const Assignment* task) {
    vector<int> zone_order = get_zone_order(task);

    int max_zone_size = max_size(task->zone_airports);

    // if an airport is unreachable, then 
    // the corresponding best_distance value is -1 
    vector<vector<int>> best_distance(2, vector<int>(max_zone_size, -1));
    best_distance[0][task->start->local_idx] = 0;

    // days are enumerate from 0
    // just like the edge's days
    vector<vector<const Edge*>> dp_restore(task->N, vector<const Edge*>(max_zone_size, nullptr));

    int day = 0;
    int prev_zone = task->start->zone;
    int reshuffle_attempts = RESHUFFLE_ATTEMPTS;
    for (int zone_ind = 0; zone_ind < task->N; ++zone_ind) {
        int zone = zone_order[zone_ind];

        best_distance[1].assign(best_distance[1].size(), -1);

        bool made_relaxation = false;

        recalc_dp(task, best_distance, dp_restore, prev_zone, zone, day, made_relaxation);

        if (!made_relaxation) {
            --reshuffle_attempts;
            if (!reshuffle_attempts or zone_ind == task->N - 1) {
                return Solution();
            }
            random_shuffle(zone_order.begin() + zone_ind, zone_order.end() - 1);
            --zone_ind;
        } else {
            reshuffle_attempts = RESHUFFLE_ATTEMPTS;
            ++day;
            max_day = max(max_day, day);
            swap(best_distance[0], best_distance[1]);
            prev_zone = zone;
        }
    }

    if (best_distance[0][task->start->local_idx] == -1) {
        return Solution();
    } else {
        return dp_construct_solution_from(task, dp_restore);
    }
}

int get_best_available_zone(const Assignment* task,
                            const vector<int>& cur_distances,
                            const set<int>& visited_zones,
                            int prev_zone,
                            int day) {
    if (day == task->N - 1) {
        return task->start->zone;
    } else {
        set<int> new_available_zones;

        for (int prev_airport = 0; prev_airport < task->zone_airports[prev_zone].size(); ++prev_airport) {
            if (cur_distances[prev_airport] != -1) {
                for (const Edge* edge : task->zone_airports[prev_zone][prev_airport]->edges_from) {
                    if ((task->max_edge_cost == -1 or edge->cost < task->max_edge_cost) and
                        (edge->day == day or edge->day == -1) and
                         edge->to->zone != task->start->zone and
                         !visited_zones.count(edge->to->zone)) {
                        assert(edge->from->local_idx == prev_airport);
                        new_available_zones.insert(edge->to->zone);
                    }
                }
            }
        }

        if (new_available_zones.empty()) {
            return -1;
        } else {
            // rewrite this >_<
            int zone_ind = random() % new_available_zones.size();
            auto zone_it = new_available_zones.begin();
            while (zone_ind) {
                ++zone_it;
                --zone_ind;
            }
            return *zone_it;
        }
    }
}

Solution dynamic_zone_order_dp(const Assignment* task) {
    int max_zone_size = max_size(task->zone_airports);
    
    // if an airport is unreachable, then 
    // the corresponding best_distance value is -1 
    vector<vector<int>> best_distance(2, vector<int>(max_zone_size, -1));
    best_distance[0][task->start->local_idx] = 0;

    // days are enumerate from 0
    // just like the edge's days
    vector<vector<const Edge*>> dp_restore(task->N, vector<const Edge*>(max_zone_size, nullptr));

    set<int> visited_zones;
    int prev_zone = task->start->zone;
    for (int day = 0; day < task->N; ++day) {
        best_distance[1].assign(best_distance[1].size(), -1);

        int zone = get_best_available_zone(task, best_distance[0], visited_zones, prev_zone, day);

        if (zone == -1) {
            return Solution();
        }

        bool made_relaxation = false;

        recalc_dp(task, best_distance, dp_restore, prev_zone, zone, day, made_relaxation);

        if (!made_relaxation) {
            return Solution();
        }

        visited_zones.insert(zone);
        prev_zone = zone;

        swap(best_distance[0], best_distance[1]);
    }

    return dp_construct_solution_from(task, dp_restore);
}

Solution run_cnt(function<Solution(Assignment*)> original, Assignment* task, int cnt) {
    Solution best = original(task);
    for(int i = 1; i < cnt; ++i) {
        Solution temp = original(task);
        temp.score();
        if(temp.correct and temp.total_score < best.total_score) {
            cerr << "Improvement from "  << best.total_score << " to " << temp.total_score << endl;
            best = temp;
        }
    }
    return best;
}

Solution run_until_tl(function<Solution(Assignment*)> original, Assignment* task) {
    Solution best = original(task);
    while (true) {
        Solution temp = original(task);
        temp.score();
        if(temp.correct and (!best.correct or temp.total_score < best.total_score)) {
            if (best.correct) cerr << "Improvement from "  << best.total_score << " to " << temp.total_score << endl;
            else cerr << "Solution found!" << endl;
            best = move(temp);
        }
        // please remove this >_<
        /*
        #ifdef DEBUG
            break;
        #endif
        */
        if(task->ready_to_stop()) {
            break;
        }
    }
    return best;
}

Solution run_binary_search_on_edges(function<Solution(Assignment*)> original, Assignment* task) {
    int max_cost = max_element(task->edges.begin(), task->edges.end())->cost;
    // this should be modified
    int min_cost = max_cost / 2;

    while (min_cost + 1 < max_cost) {
        int med_cost = (min_cost + max_cost) / 2;
        task->max_edge_cost = med_cost;
        bool success = false;
        for (int i = 0; i < MAX_ATTEMPT; ++i) {
            Solution solution = original(task);
            solution.score();
            if (solution.correct) {
                success = true;
                break;
            }
        }

        if (success) {
            max_cost = med_cost;
        } else {
            min_cost = med_cost;
        }
    }

    task->max_edge_cost = max_cost;

    return run_until_tl(original, task);
}

int main() {
    Assignment task;

    srand(1357908642);
   
    cerr << "Starting" << endl;
    string start_airport_str, input;
    cin >> task.N >> start_airport_str;
    getline(cin,input);

    // one dirty hack to avoid reallocations
    task.airports.reserve(MAX_AIRPORT);
    
    task.zones.resize(task.N);
    for(int i = 0; i < task.N; ++i) {
        getline(cin, task.zones[i]);
        string airports_raw;
        getline(cin, airports_raw);
        istringstream iss(airports_raw);
        string item;
        task.zone_airports.push_back({});
        int cur_local_idx = 0;
        while (getline(iss, item, ' ')) {
            if (task.airport_name_to_idx.find(item) == task.airport_name_to_idx.end()) {
                task.airport_name_to_idx[item] = task.idx_to_airport.size();
                task.idx_to_airport.push_back(item);
            }     
            task.airports.push_back({ static_cast<int>(task.airports.size()), i, cur_local_idx });
            task.zone_airports[i].push_back(&task.airports.back());
            ++cur_local_idx;
        }
    }

    // cerr << task.zones[0] << endl;
    cerr << "Airports read" << endl;
    task.start = &task.airports[task.airport_name_to_idx[start_airport_str]];
    while(!cin.eof()) {
        string from, to;
        // cerr << from << to << endl;
        int day, cost;
        cin >> from >> to >> day >> cost;
        task.edges.push_back({
            &task.airports[task.airport_name_to_idx[from]],
            &task.airports[task.airport_name_to_idx[to]],
            day - 1,
            cost}
        );
    }

    task.init();
    cerr << "Assignment initialised" << endl;

    // Solution sol = solve_simple(&task);
    Solution sol = run_until_tl(dynamic_zone_order_dp, &task);
     if(!sol.correct) {
        cerr << "SOLUTION INCORRECT!" << endl;
    }
    cerr << "Completed in: " << std::chrono::duration_cast<chrono::milliseconds>(Clock::now() - task.start_time).count() << endl;
    sol.score();
    cerr << "Score: " << sol.total_score << endl;
    cerr << "Max day reached: " << max_day << endl;
    sol.print();
	return 0;
}