
#include "newmain.cpp" //nosubmit

int main() {
    read_and_solve([](Assignment* task){
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
    });
}