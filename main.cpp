#include <algorithm>
#include <assert.h>
#include <chrono>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
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


#include "basic_structs.cpp" //nosubmit
#include "run.cpp" //nosubmit
#include "dp.cpp" //nosubmit
#include "greedy.cpp" //nosubmit
#include "local_search.cpp" //nosubmit

Solution solve_simple(Assignment* task) {
    Solution sol(task);
    Airport* current_place = task->start;
    std::vector<bool> visited(task->N);
    visited[current_place->zone] = true;
    for (int current_day = 1; current_day<= task->N; ++current_day) {
        int limit = current_place->edges_from.size();
        if(limit!=0) {
            int offset = rand() % limit;
            if (current_day == task->N) {
                visited[task->start->zone] = false;
            }
            for (int i = 0; i < limit; ++i) {
                int idx = (i + offset) % limit;
                Edge* e = current_place->edges_from[idx];
                if (!visited[e->to->zone] and (e->day == 0 or e->day == current_day)) {
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

Solution do_final_solve(Assignment* task){
    Solution sol = run_main(solve_simple, task);
    sol.score();
    cerr << "SIMPLE SCORE " << sol.total_score << '\n';
    if(!sol.correct) {
        cerr << "SIMPLE SOLUTION INCORRECT!" << endl;
    }
    // sol = solve_local_search(task, sol);
    // sol = edges_number_binary_search(greedy, solve_local_search, task);
    // sol = run_main(greedy, task);
    return sol;
}


int main() {
    srand(1357908642);

    Assignment task;

    ios_base::sync_with_stdio(false);

    task.read_data();
    
    task.init_edges();

    cerr << "Assignment initialised" << endl;
    Solution sol = do_final_solve(&task);
    sol.score();
    if(!sol.correct) {
        cerr << "SOLUTION INCORRECT!" << endl;
    }
    cerr << "Completed in: " << std::chrono::duration_cast<chrono::milliseconds>(Clock::now() - task.start_time).count() << endl;
    cerr << "Score: " << sol.total_score << endl;
    sol.print();
	return 0;
}