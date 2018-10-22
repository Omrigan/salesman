#include "basic_structs.cpp" //nosubmit

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

Solution run_until_correct(function<Solution(Assignment*)> original, Assignment* task) {
    Solution best = original(task);
    while(!best.correct) {
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
