#include "basic_structs.cpp" //nosubmit

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
                                function<Solution(Assignment*, Solution&)> second_solution,
                                Assignment* task) {
    Solution best = first_solution(task);
    best.score();
    while (true) {
        Solution temp = first_solution(task);
        temp.score();
        if (temp.correct and (!best.correct or temp.total_score < best.total_score)) {
            if (best.correct) cerr << "Improvement from "  << best.total_score << " to " << temp.total_score << endl;
            else cerr << "Solution found!" << endl;
            best = move(temp); 
        }
        int64_t now_ms_long = get_time_in_ms(Clock::now());
        if (((now_ms_long - task->start_time_long) * 3) / 2 > (task->finish_time_long - task->start_time_long)) {
            break;
        }
    }

    // remove when release
    assert(best.correct);

    while (true) {
        best = second_solution(task, best);
        if (task->ready_to_stop()) {
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

// call this only with "greedy" function
Solution edges_number_binary_search(function<Solution(Assignment*)> bs_solution,
                                    function<Solution(Assignment*, Solution&)> final_solution,
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

    // modify this!
    int margin = 2;
    max_edges_cnt = min(max_edges_cnt + margin, get_max_edges_cnt(task));
    task->max_edge_index = max_edges_cnt;

    cerr << "Maximum edge index: " << task->max_edge_index << endl;
    cerr << "Maximum edge count: " << get_max_edges_cnt(task) << endl;

    Solution main_solution = run_multiple_solutions(bs_solution, final_solution, task);

    if (!best_solution.correct or best_solution.total_score > main_solution.total_score) {
        best_solution = move(main_solution);
    }

    return best_solution;
}

