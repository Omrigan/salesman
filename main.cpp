// TODO: unify variables namestyle

#include "basic_structs.cpp" //nosubmit
#include "run.cpp" //nosubmit
#include "dp.cpp" //nosubmit
#include "greedy.cpp" //nosubmit
#include "local_search.cpp" //nosubmit

mt19937_64 RandomGenerator::gen_rand(RandomGenerator::seed);
uniform_int_distribution<> RandomGenerator::distr;
uniform_int_distribution<long long> RandomGenerator::distr_long;

int RandomGenerator::get_rand_int() {
    return RandomGenerator::distr(RandomGenerator::gen_rand);
}

long long RandomGenerator::get_rand_int64() {
    return RandomGenerator::distr_long(RandomGenerator::gen_rand);
}

using Clock = chrono::steady_clock;
using Microseconds = chrono::microseconds;
using Time = Clock::time_point;

Solution solve_simple(Assignment* task) {
    Solution sol(task);
    Airport* current_place = task->start;
    std::vector<bool> visited(task->N);
    visited[current_place->zone] = true;
    for (int current_day = 1; current_day<= task->N; ++current_day) {
        int limit = current_place->edges_from.size();
        if(limit!=0) {
            int offset = RandomGenerator::get_rand_int() % limit;
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
    Solution sol = run_main(solve_simple, task, true);
    sol.score();
    cerr << "SIMPLE SCORE " << sol.total_score << '\n';
    if(!sol.correct) {
        cerr << "SIMPLE SOLUTION INCORRECT!" << endl;
    }
    // sol = solve_local_search(task, sol);
    sol = edges_number_binary_search(greedy, solve_local_search, task);
    // sol = run_main(greedy, task);
    return sol;
}

int main() {
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
    cerr << "Completed in: " << chrono::duration_cast<chrono::milliseconds>(Clock::now() - task.start_time).count() << endl;
    cerr << "Score: " << sol.total_score << endl;
    cerr << "Max day reached: " << max_day << endl;
    sol.print();
	return 0;
}