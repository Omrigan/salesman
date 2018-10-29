#include <algorithm>
#include <assert.h>
#include <chrono>
#include <functional>
#include <iostream>
#include <iterator>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "basic_structs.cpp" //nosubmit
//ничего нипанятна опишите аргументы
Solution run_main(function<Solution(Assignment*)> original, 
                  Assignment* task, 
                  bool return_first_solution = false,
                  int cnt = -1) {
    Solution best = original(task);
    best.score();
    int all_runs = 0;
    int successful_runs = 0;
    while (true) {
        Solution temp = original(task);
        temp.score();
        successful_runs += temp.correct;
        ++all_runs;
        if (temp.correct and (!best.correct or temp.total_score < best.total_score)) {
            if (best.correct) cerr << "Improvement from "  << best.total_score << " to " << temp.total_score << endl;
            else cerr << "Solution found!" << endl;
            best = move(temp);
            if (return_first_solution) return best; 
        }
        if (task->ready_to_stop()) {
            break;
        }
        cnt = max(cnt - 1, -1);
        if (cnt == 0) {
            return best;
        }
    }

    cerr << "Total number of runs: " << all_runs << endl;
    cerr << "Successful number of runs: " << successful_runs << endl;
    cerr << "Successful runs ratio: " << successful_runs / static_cast<double>(all_runs) << endl;

    return best;
}

Solution run_multiple_solutions(function<Solution(Assignment*)> first_solution,
                                function<Solution(Assignment*, Solution)> second_solution,
                                Assignment* task) {
    Solution best_solution = first_solution(task);
    best_solution.score();

    vector<Solution> solutions(task->number_of_considered_solutions);
    solutions[0] = best_solution;

    int all_runs = 0;
    int successful_runs = 0;
    
    while (true) {
        Solution temp = first_solution(task);
        temp.score();
        ++all_runs;
        successful_runs += temp.correct;

        if (temp.correct) {
            int worst_index = -1;
            for (int i = 0; i < task->number_of_considered_solutions; ++i) {
                if (!solutions[i].correct or solutions[i].total_score > temp.total_score) {
                    if (worst_index == -1 or
                        !solutions[i].correct or 
                        (solutions[worst_index].total_score < solutions[i].total_score and
                        solutions[worst_index].correct)) {
                        worst_index = i;
                    }
                }
            }
            if (worst_index != -1) {
                solutions[RandomGenerator::get_rand_int() % task->number_of_considered_solutions] = temp;
                if (!best_solution.correct or temp.total_score < best_solution.total_score) {
                    if (best_solution.correct) cerr << "Improvement from "  << best_solution.total_score << " to " << temp.total_score << endl;
                    else cerr << "Solution found! It scored " << temp.total_score << endl;
                    best_solution = move(temp); 
                }
            }
        }

        int64_t now_ms_long = get_time_in_ms(Clock::now());
        if ((now_ms_long - task->start_time_long) * task->greedy_solution_runtime > (task->finish_time_long - task->start_time_long)) {
            break;
        }
    }

    cerr << "~~~~~~~~~~~~~~~" << endl;
    for (Solution& solution : solutions) {
        cerr << solution.total_score << endl;
    }
    cerr << "~~~~~~~~~~~~~~~" << endl;

    cerr << "Total number of runs: " << all_runs << endl;
    cerr << "Successful number of runs: " << successful_runs << endl;
    cerr << "Successful runs ratio: " << successful_runs / static_cast<double>(all_runs) << endl;

    if (!best_solution.correct) {
        cerr << "FIRST SOLUTION FOUND NO CORRECT PATH!" << endl;
    } else {
        cerr << "Score before local solve: " << best_solution.total_score << endl;
    }

    while (true) {
        for (Solution& solution : solutions) {
            solution = second_solution(task, move(solution));
            if (solution.correct and (!best_solution.correct or solution.total_score < best_solution.total_score)) {
                if (best_solution.correct) cerr << "Improvement from "  << best_solution.total_score << " to " << solution.total_score << endl;
                else cerr << "Solution found! It scored " << solution.total_score << endl;
                best_solution = solution;
            }
            if (task->ready_to_stop()) {
               break;
            }
        }
        if (task->ready_to_stop()) {
            break;
        }
    }

    cerr << "~~~~~~~~~~~~~~~" << endl;
    for (Solution& solution : solutions) {
        cerr << solution.total_score << endl;
    }
    cerr << "~~~~~~~~~~~~~~~" << endl;

    return best_solution;
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
        for (int i = 0; i < MAX_ATTEMPT_EDGES_COST; ++i) {
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

    Solution tmp_solution = run_main(original, task);
    if (tmp_solution.correct and
        (!best_solution.correct or
        (best_solution.total_score > tmp_solution.total_score))) {
        best_solution = move(tmp_solution);
    }

    return best_solution;
}

int get_max_edges_cnt(const Assignment* task) {
    int ret = 0;
    for (const Airport& airport : task->airports) {
        for (int day = 1; day <= task->N; ++day) {
            ret = max(ret, static_cast<int>(airport.edges_from_by_day[day].size() + airport.edges_from_by_day[0].size()));
        }
    }
    return ret;
}

// bs stands for binary search
Solution get_max_edges_index_bs(function<Solution(Assignment*)> bs_solution,
                                Assignment* task) {
    int min_edges_cnt = 0;
    int max_edges_cnt = get_max_edges_cnt(task);

    Solution best_solution;
    best_solution.score();
    
    while (min_edges_cnt + 1 < max_edges_cnt) {
        int med_edges_cnt = (min_edges_cnt + max_edges_cnt) / 2;
        bool success = false;
        for (int i = 0; i < MAX_ATTEMPT_EDGES_CNT; ++i) {
            task->max_edge_index = med_edges_cnt;
            Solution sol = bs_solution(task);
            sol.score();
            if (sol.correct) {
                if (!best_solution.correct or best_solution.total_score > sol.total_score) {
                    best_solution = move(sol);
                }
                success = true;
                break;
            }
        }
        if (success) {
            max_edges_cnt = med_edges_cnt;
        } else {
            min_edges_cnt = med_edges_cnt;
        }
    }
    task->max_edge_index = max_edges_cnt;

    return best_solution;
}

// ls stands for linear search
Solution get_max_edges_index_ls(function<Solution(Assignment*)> bs_solution,
                                Assignment* task,
                                int left, int right) {
    Solution best_solution;
    best_solution.score();

    // if best_solution stays uninitialized
    int best_max_edge_index = (left + right) / 2;

    for (int max_edge_index = left; max_edge_index <= right; ++max_edge_index) {
        task->max_edge_index = max_edge_index;
        for (int j = 0; j < MAX_ATTEMPT_EDGES_CNT; ++j) {
            Solution sol = bs_solution(task);
            sol.score();
            if (sol.correct and (!best_solution.correct or best_solution.total_score > sol.total_score)) {
                best_solution = move(sol);
                best_max_edge_index = max_edge_index;
            }
        }
    }
    
    task->max_edge_index = best_max_edge_index;

    return best_solution;
}

Solution calibrate_max_edges_index(function<Solution(Assignment*)> max_edges_index_solution,
                                   function<Solution(Assignment*, Solution)> final_solution,
                                   Assignment* task) {
    Solution best_solution = get_max_edges_index_bs(max_edges_index_solution, task);
    best_solution = get_max_edges_index_ls(max_edges_index_solution, 
                                           task, 
                                           max(task->max_edge_index - task->margin, 1),
                                           min(task->max_edge_index + task->margin, get_max_edges_cnt(task)));

    cerr << "Maximum edge index: " << task->max_edge_index << endl;
    cerr << "Maximum edge count: " << get_max_edges_cnt(task) << endl;

    Solution main_solution = run_multiple_solutions(max_edges_index_solution, final_solution, task);

    cerr << "Solution found when calibrating max edges index is " << (best_solution.correct ? "" : "in") << "correct" << endl;
    if (best_solution.correct) cerr << "It scores " << best_solution.total_score << endl;
    cerr << "Main score: " << main_solution.total_score << endl;

    if (!best_solution.correct or best_solution.total_score >= main_solution.total_score) {
        best_solution = move(main_solution);
    } else {
        cerr << "MAIN SOLUTION IS WORSE THAN SIMPLE BINARY SEARCH!" << endl;
    }

    return best_solution;
}
