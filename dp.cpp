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

struct Solution;
struct Assignment;
struct Edge;
struct Airport;

#include "basic_structs.cpp" //nosubmit

vector<int> get_zone_order(const Assignment* task) {
    vector<int> zone_order;
    for (int i = 0; i < task->N; ++i) {
        if (i != task->start->zone) zone_order.push_back(i);
    }
    random_shuffle(zone_order.begin(), zone_order.end());
    zone_order.push_back(task->start->zone);
    return zone_order;
}

int max_size(const vector<vector<Airport*>>& v) {
    int max_size = 0;
    for (const vector<Airport*> a : v) {
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
                if ((task->max_edge_cost == -1 or edge->cost < task->max_edge_cost) and
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
                    if ((task->max_edge_cost == -1 or edge->cost <= task->max_edge_cost) and
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
