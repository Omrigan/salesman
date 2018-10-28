#include <algorithm>
#include <assert.h>
#include <chrono>
#include <functional>
#include <iostream>
#include <iterator>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <thread>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <climits>

using namespace std;

#include "basic_structs.cpp"

using Mutate = function<Solution(Assignment*,const Solution&)>;

double temp(Assigment* task){
    double time_elapsed = double(get_time_in_ms(Clock::now())-task->start_time_long)/task->time_to_live;
    return time_elapsed;

}
double prob(double score_old, double score_new, double temp){
    return 1;
}

Solution run_annealing(Mutate mut,Assignment* task, Solution current){
    
    while(!task->ready_to_stop()){
        Solution candidate = mut(task, current);
        candidate.score();
        double t = temp(task);
        double p = prob(current.total_score, candidate.total_score, t);
        if(p>RandomGenerator::get_rand_prob()){
            
        }
    }



}