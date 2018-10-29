
#include "../newmain.cpp"

int main() {
    read_and_solve([](Assignment* task){
        Solution sol = run_main(solve_simple, task, true);
        sol.score();
        cerr << "SIMPLE SCORE " << sol.total_score << '\n';
        if(!sol.correct) {
            cerr << "SIMPLE SOLUTION INCORRECT!" << endl;
        }
        // sol = solve_local_search(task, sol);
        task->use_random_swaps = true;
        task->use_experimental_temp = true;
        sol = calibrate_max_edges_index(greedy, LocalOptimizeManager::apply_random_optimization, task);
        // sol = calibrate_max_edges_index(greedy, solve_local_search, task);
        // sol = run_main(greedy, task);
        return sol;
    });
}