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
#include <stdio.h>
#include <stdlib.h>

using namespace std;



Solution solve_local_search(Assignment *task, Solution & sol) {
    sol.score();
    long long total_cost = sol.total_score; // want to minimize
    const int MAX_ITER_INNER = 150;
    const int MAX_ITER_OUTER = 10000000;
    long long COST_INF = 10000000000;
    const int MAX_TIME = 300;
    //  const int MAX_REGION = 300;
    std::vector<std::vector<std::vector<Edge * > > > canfromto;
    canfromto.resize(MAX_TIME + 1, std::vector<std::vector<Edge * > > (MAX_AIRPORT, std::vector<Edge * > (MAX_AIRPORT, nullptr)));
    // preprocessing
    for (auto & edge : task->edges) {
        if (edge.day == 0) {
            for (int day = 1; day <= MAX_TIME; day++) {
                canfromto[day][edge.from->idx][edge.to->idx] = &edge;
            }
            continue;
        }
        canfromto[edge.day][edge.from->idx][edge.to->idx] = &edge;
    }
    auto basic_seq = sol.sequence;
    auto global_best_sequence = sol.sequence;
    long long global_best_score = COST_INF;
    for (int j = 0; j < MAX_ITER_OUTER && !task->ready_to_stop(); j++) {
        sol.sequence = basic_seq;
        for (int p = 0; p < MAX_ITER_INNER && !task->ready_to_stop(); p++) {
            std::vector<std::pair<int, int> > tries;
            for (int first = 0; first < sol.sequence.size() - 3; first++) {
                for (int second = first + 2; second < sol.sequence.size() - 1; second++) {
                    tries.push_back({first, second});
                }
            }
            std::random_shuffle(tries.begin(), tries.end());
            //  выбираем пару объектов в цепочке
            int max_edge_id = sol.sequence.size(); // видимо первый не трогаем, а последний обрабатываем отдельно
            if (max_edge_id <= 3)
                return sol;
            for (auto &tst : tries) {
                int first = tst.first; // rand() % (max_edge_id - 3); // [1, max_edge_id - 1]
                int second = tst.second; // rand() % (max_edge_id - first - 3) + first + 2;
                if (second < first + 2)
                    cerr << "WRONG RANDOM";


                std::pair<const Edge *, const Edge *> A = {sol.sequence[first], sol.sequence[first + 1]};
                std::pair<const Edge *, const Edge *> B = {sol.sequence[second], sol.sequence[second + 1]};
                std::pair<Edge *, Edge *> A_new;
                std::pair<Edge *, Edge *> B_new;
                long long min_cost = COST_INF;
                long long delta_cost = 0;
                delta_cost -= A.first->cost + A.second->cost + B.first->cost + B.second->cost;
                Airport *midA = A.first->to;
                Airport *midB = B.first->to;
                for (auto airp : task->zone_airports[midA->zone]) {
                    // заходим в зону A
                    // B.from -> Amid -> B.to
                    Edge *e1 = canfromto[second + 1][B.first->from->idx][airp->idx];
                    Edge *e2 = canfromto[second + 1 + 1][airp->idx][B.second->to->idx];
                    if (e1 != nullptr && e2 != nullptr) {
                        long long cost = e1->cost + e2->cost;
                        if (min_cost > cost) {
                            min_cost = cost;
                            B_new = {e1, e2};
                        }
                    }
                }
                if (min_cost == COST_INF) {
                    // нет необходимых рейсов
                    continue;
                }
                delta_cost += min_cost;
                min_cost = COST_INF;
                for (auto airp : task->zone_airports[midB->zone]) {
                    // заходим в зону B
                    // A.from -> Bmid -> B.to
                    Edge *e1 = canfromto[first + 1][A.first->from->idx][airp->idx];
                    Edge *e2 = canfromto[first + 1 + 1][airp->idx][A.second->to->idx];
                    if (e1 != nullptr && e2 != nullptr) {
                        long long cost = e1->cost + e2->cost;
                        if (min_cost > cost) {
                            min_cost = cost;
                            A_new = {e1, e2};
                        }
                    }
                }
                if (min_cost == COST_INF) {
                    // нет необходимых рейсов
                    continue;
                }
                delta_cost += min_cost;
                if (delta_cost < 0) {
                    //  поменять ребра в sol
                    sol.sequence[first] = A_new.first;
                    sol.sequence[first + 1] = A_new.second;
                    sol.sequence[second] = B_new.first;
                    sol.sequence[second + 1] = B_new.second;
                    total_cost += delta_cost;
                }
            }
            sol.score();
            if (sol.total_score < global_best_score) {
                cerr << "CURRENT BEST GLOBAL SCORE " << sol.total_score << '\n';
                global_best_score = sol.total_score;
                global_best_sequence = sol.sequence;
            }
        }
    }
    sol.sequence = global_best_sequence;
    sol.score();
    return sol;
}