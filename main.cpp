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
// TODO: apply const qualifiers when necessary

using Clock = chrono::steady_clock;
using Microseconds = chrono::microseconds;
using Time = Clock::time_point;


#include "basic_structs.cpp" // nosubmit
#include "dp.cpp" //nosubmit

Solution solve_simple(Assignment* task) {
    Solution sol{ .task = task };
    Airport* current_place = task->start;
    vector<bool> visited(task->N);
    visited[current_place->zone] = true;
    for(int current_day = 0; current_day<task->N; ++current_day){
        int limit = current_place->edges_from.size();
        if(limit!=0){
           
            int offset = rand() % limit;
            if(current_day==task->N-1)
            {
                visited[task->start->zone] = false;
            }
            for(int i = 0; i < limit;++i){
                int idx = (i+offset)%limit;
                Edge* e = current_place->edges_from[idx];
                if(!visited[e->to->zone] and (e->day==-1 or e->day==current_day)){
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