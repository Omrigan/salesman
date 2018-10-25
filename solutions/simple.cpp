#include "../newmain.cpp"

int main(){
    read_and_solve([](Assignment * task){
        Solution sol = run_main(solve_simple, task);
        return sol;
    });
}