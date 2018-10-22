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
#include <thread>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// TODO: unify variables namestyle
// TODO: use better random

using Clock = chrono::steady_clock;
using Microseconds = chrono::microseconds;
using Time = Clock::time_point;


#include "basic_structs.cpp" // nosubmit
#include "dp.cpp" //nosubmit
#include "greedy.cpp" //nosubmit

Solution solve_simple(Assignment* task) {
    Solution sol{ .task = task };
    Airport* current_place = task->start;
    std::vector<bool> visited(task->N);
    visited[current_place->zone] = true;
    for(int current_day = 1; current_day<= task->N; ++current_day){
        int limit = current_place->edges_from.size();
        if(limit!=0){
           
            int offset = rand() % limit;
            if(current_day == task->N) {
                visited[task->start->zone] = false;
            }
            for(int i = 0; i < limit; ++i){
                int idx = (i + offset) % limit;
                Edge* e = current_place->edges_from[idx];
                if(!visited[e->to->zone] and (e->day == 0 or e->day == current_day)){
                    sol.sequence.push_back(e);
                    current_place = e->to;
                    visited[current_place->zone] = true;
                    break;
                }
            }
        }
    }
    sol.score();
    return sol;
}

// ToDo разобраться с последним ребром
Solution solve(Assignment *task, Solution & sol) {
    sol.score();
    long long total_cost = sol.total_score; // want to minimize
    const int MAX_ITER_INNER = 100000;
    const int MAX_ITER_OUTER = 10000000;
    long long COST_INF = 10000000000;
    const int MAX_TIME = 300;
    //  const int MAX_REGION = 300;
    std::vector<std::vector<std::vector<Edge * > > > canfromto;
    canfromto.resize(MAX_TIME + 1, std::vector<std::vector<Edge * > > (MAX_AIRPORT, std::vector<Edge * > (MAX_AIRPORT, nullptr)));
    // preprocessing
    for (auto & edge : task->edges) {
        if (edge.day == 0) {
            for (int day = 1; day <= MAX_TIME; day++) {
                canfromto[day][edge.from->idx][edge.to->idx] = &edge;
            }
            continue;
        }
        canfromto[edge.day][edge.from->idx][edge.to->idx] = &edge;
    }
    auto global_best_sequence = sol.sequence;
    long long global_best_score = COST_INF;
    for (int j = 0; j < MAX_ITER_OUTER && !task->ready_to_stop(); j++) {
        for (int i = 0; i < MAX_ITER_INNER && !task->ready_to_stop(); i++) {
            //  выбираем пару объектов в цепочке
            int max_edge_id = sol.sequence.size(); // видимо первый не трогаем, а последний обрабатываем отдельно
            if (max_edge_id <= 3)
                return sol;
            int first = rand() % (max_edge_id - 3); // [1, max_edge_id - 1]
            int second = rand() % (max_edge_id - first - 3) + first + 2;
            if (second < first + 2)
                cerr << "WRONG RANDOM";


            std::pair<const Edge *, const Edge *> A = {sol.sequence[first], sol.sequence[first + 1]};
            std::pair<const Edge *, const Edge *> B = {sol.sequence[second], sol.sequence[second + 1]};
            std::pair<Edge *, Edge *> A_new;
            std::pair<Edge *, Edge *> B_new;
            long long min_cost = COST_INF;
            long long delta_cost = 0;
            delta_cost -= A.first->cost + A.second->cost + B.first->cost + B.second->cost;
            Airport *midA = A.first->to;
            Airport *midB = B.first->to;
            for (auto airp : task->zone_airports[midA->zone]) {
                // заходим в зону A
                // B.from -> Amid -> B.to
                Edge *e1 = canfromto[second][B.first->from->idx][airp->idx];
                Edge *e2 = canfromto[second + 1][airp->idx][B.second->to->idx];
                if (e1 != nullptr && e2 != nullptr) {
                    long long cost = e1->cost + e2->cost;
                    if (min_cost > cost) {
                        min_cost = cost;
                        B_new = {e1, e2};
                    }
                }
            }
            if (min_cost == COST_INF) {
                // нет необходимых рейсов
                continue;
            }
            delta_cost += min_cost;
            min_cost = COST_INF;
            for (auto airp : task->zone_airports[midB->zone]) {
                // заходим в зону B
                // A.from -> Bmid -> B.to
                Edge *e1 = canfromto[first][A.first->from->idx][airp->idx];
                Edge *e2 = canfromto[first + 1][airp->idx][A.second->to->idx];
                if (e1 != nullptr && e2 != nullptr) {
                    long long cost = e1->cost + e2->cost;
                    if (min_cost > cost) {
                        min_cost = cost;
                        A_new = {e1, e2};
                    }
                }
            }
            if (min_cost == COST_INF) {
                // нет необходимых рейсов
                continue;
            }
            delta_cost += min_cost;
            if (delta_cost < 0) {
                //  поменять ребра в sol
                sol.sequence[first] = A_new.first;
                sol.sequence[first + 1] = A_new.second;
                sol.sequence[second] = B_new.first;
                sol.sequence[second + 1] = B_new.second;
                total_cost += delta_cost;
            }
        }
        // FOR DEBUG ONLY
        for (int i = 0; i < sol.sequence.size() - 1; i++) {
            if (sol.sequence[i]->to != sol.sequence[i + 1]->from) {
                cerr << "SEQUENCE INCORRECT!\n";
            }
        }
        sol.score();
        if (sol.total_score < global_best_score) {
            cerr << "CURRENT BEST GLOBAL SCORE " << sol.total_score << '\n';
            global_best_score = sol.total_score;
            global_best_sequence = sol.sequence;
        }
    }
    sol.sequence = global_best_sequence;
    sol.score();
    return sol;
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
    while(true) {
        Solution temp = original(task);
        temp.score();
        if(temp.correct and (!best.correct or temp.total_score < best.total_score)) {
            if (best.correct) cerr << "Improvement from "  << best.total_score << " to " << temp.total_score << endl;
            else cerr << "Solution found!" << endl;
            best = move(temp);
        }
        if(task->ready_to_stop()) {
            break;
        }
    }
    return best;
}

Solution run_binary_search_on_edges(function<Solution(Assignment*)> original, Assignment* task) {
    int max_cost = max_element(task->edges.begin(), task->edges.end())->cost;
    // this should be modified
    int min_cost = 0;

    Solution best_solution;

    while (min_cost + 1 < max_cost) {
        int med_cost = (min_cost + max_cost) / 2;
        task->max_edge_cost = med_cost;
        bool success = false;
        for (int i = 0; i < MAX_ATTEMPT; ++i) {
            Solution tmp_solution = original(task);
            tmp_solution.score();
            if (tmp_solution.correct) {
                if (!best_solution.correct or
                    (best_solution.total_score > tmp_solution.total_score)) {
                    best_solution = move(tmp_solution);
                }
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

    Solution tmp_solution = run_until_tl(original, task);
    if (tmp_solution.correct and
        (!best_solution.correct or
        (best_solution.total_score > tmp_solution.total_score))) {
        best_solution = move(tmp_solution);
    }

    return best_solution;
}

int main() {
    Assignment task;
    // debug
    // FILE * f = freopen("/Users/istar/Desktop/salesman/public/1.in", "r", stdin);
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

    cerr << "Airports read" << endl;
    task.start = &task.airports[task.airport_name_to_idx[start_airport_str]];
    while(!cin.eof()) {
        string from, to;
        int day, cost;
        cin >> from >> to >> day >> cost;
        task.edges.push_back({
            &task.airports[task.airport_name_to_idx[from]],
            &task.airports[task.airport_name_to_idx[to]],
            day,
            cost}
        );
    }

    task.init();

    /*
    cerr << "Assignment initialised" << endl;
    Solution sol = solve_simple(&task);
    sol.score();
    cerr << "SIMPLE SCORE " << sol.total_score << '\n';
    if(!sol.correct) {
        cerr << "SIMPLE SOLUTION INCORRECT!" << endl;
        // sol = run_binary_search_on_edges(dynamic_zone_order_dp, &task);
    }
    sol = solve(&task, sol);
    // Solution sol = run_binary_search_on_edges(dynamic_zone_order_dp, &task);
    if(!sol.correct) {
        cerr << "SOLUTION INCORRECT!" << endl;
    }
    */
    Solution sol = run_until_tl(greedy, &task);
    sol.score();
    if(!sol.correct) {
        cerr << "SOLUTION INCORRECT!" << endl;
    }
    cerr << "Completed in: " << std::chrono::duration_cast<chrono::milliseconds>(Clock::now() - task.start_time).count() << endl;
    cerr << "Score: " << sol.total_score << endl;
    cerr << "Max day reached: " << max_day << endl;
    sol.print();
	return 0;
}