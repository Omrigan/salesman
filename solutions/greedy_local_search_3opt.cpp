#include "../newmain.cpp"

int main(){
    read_and_solve([](Assignment * task){
        Solution sol = run_multiple_solutions(greedy, solve_local_search_3v, task);
        return sol;
    });
}

