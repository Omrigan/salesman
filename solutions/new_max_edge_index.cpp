#include "../newmain.cpp"

int main() {
    read_and_solve([](Assignment* task){
        Solution sol = run_main(solve_simple, task, true);
        sol.score();
        cerr << "SIMPLE SCORE " << sol.total_score << '\n';
        if(!sol.correct) {
            cerr << "SIMPLE SOLUTION INCORRECT!" << endl;
        }
        sol = calibrate_max_edges_index(greedy, solve_local_search, task);
        return sol;
    });
}