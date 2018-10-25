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

#include "basic_structs.cpp"
bool swap_anyway(const Assignment* task, int total_cost, int delta_cost) {
    if (task->use_random_swaps) {
        return total_cost / (10000 * static_cast<double>(delta_cost)) > RandomGenerator::get_rand_int() / static_cast<double>(__INT_MAX__);
    }
    return false;
}
int random(int a, int b) {
    if (b <= a)
        cerr << "INVALID ARGUMENT\n";
    return RandomGenerator::get_rand_int() % (b - a) + a;
}

Solution solve_local_search(Assignment *task, Solution sol) {
    sol.score();
    long long total_cost = sol.total_score; // want to minimize
    const int MAX_ITER_INNER = 150;
    const int MAX_ITER_OUTER = 10000000;
    long long COST_INF = 10000000000;

    //  const int MAX_REGION = 300;
    // preprocessing
    task->init_can_from_to();

    auto basic_seq = sol.sequence;
    auto global_best_sequence = sol.sequence;
    long long global_best_score = total_cost;
    for (int j = 0; j < MAX_ITER_OUTER && !task->ready_to_stop(); j++) {
        sol.sequence = basic_seq;
        for (int p = 0; p < MAX_ITER_INNER && !task->ready_to_stop(); p++) {
            std::vector<std::pair<int, int> > tries;
            for (int first = 0; first < static_cast<int>(sol.sequence.size()) - 3; first++) {
                for (int second = first + 2; second < static_cast<int>(sol.sequence.size()) - 1; second++) {
                    tries.push_back({first, second});
                }
            }
            shuffle(tries.begin(), tries.end(), RandomGenerator::gen_rand);
            //  выбираем пару объектов в цепочке
            int max_edge_id = sol.sequence.size(); // видимо первый не трогаем, а последний обрабатываем отдельно
            if (max_edge_id <= 3)
                return sol;
            for (auto &tst : tries) {
                int first = tst.first; // RandomGenerator::get_rand_int() % (max_edge_id - 3); // [1, max_edge_id - 1]
                int second = tst.second; // RandomGenerator::get_rand_int() % (max_edge_id - first - 3) + first + 2;
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
                    Edge *e1 = task->canfromto[second + 1][B.first->from->idx][airp->idx];
                    Edge *e2 = task->canfromto[second + 1 + 1][airp->idx][B.second->to->idx];
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
                    Edge *e1 = task->canfromto[first + 1][A.first->from->idx][airp->idx];
                    Edge *e2 = task->canfromto[first + 1 + 1][airp->idx][A.second->to->idx];
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
                if (delta_cost <= 0 or swap_anyway(task, total_cost, delta_cost)) {
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
    sol.sequence = move(global_best_sequence);
    sol.score();
    return sol;
}

vector<int> generate_k(int k, int n) {
    vector<int> ar = {};
    for (int i = 0; i < k; i++) {
        ar.push_back(random(ar.size() == 0 ? 0 : ar[ar.size() - 1], n - 2 * (k - i)));
    }
    return ar;
}

Solution solve_local_search_combined(Assignment *task, Solution sol) {
    sol.score();
    long long total_cost = sol.total_score; // want to minimize
    const int MAX_ITER_INNER = 25;
    const int MAX_ITER_OUTER = 10000000;
    //  const int ITER_3SWAP = 100;
    long long COST_INF = 10000000000;


    //  const int MAX_REGION = 300;
    // preprocessing
    task->init_can_from_to();

    auto basic_seq = sol.sequence;
    auto global_best_sequence = sol.sequence;
    long long global_best_score = total_cost;
    for (int j = 0; j < MAX_ITER_OUTER && !task->ready_to_stop(); j++) {
        sol.sequence = basic_seq;
        for (int p = 0; p < MAX_ITER_INNER && !task->ready_to_stop(); p++) {
            std::vector<std::pair<int, int> > tries;
            for (int first = 0; first < static_cast<int>(sol.sequence.size()) - 3; first++) {
                for (int second = first + 2; second < static_cast<int>(sol.sequence.size()) - 1; second++) {
                    tries.push_back({first, second});
                }
            }
            shuffle(tries.begin(), tries.end(), RandomGenerator::gen_rand);
            //  выбираем пару объектов в цепочке
            int max_edge_id = sol.sequence.size(); // видимо первый не трогаем, а последний обрабатываем отдельно
            if (max_edge_id <= 3)
                return sol;
            for (auto &tst : tries) {
                int first = tst.first; // RandomGenerator::get_rand_int() % (max_edge_id - 3); // [1, max_edge_id - 1]
                int second = tst.second; // RandomGenerator::get_rand_int() % (max_edge_id - first - 3) + first + 2;
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
                    Edge *e1 = task->canfromto[second + 1][B.first->from->idx][airp->idx];
                    Edge *e2 = task->canfromto[second + 1 + 1][airp->idx][B.second->to->idx];
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
                    Edge *e1 = task->canfromto[first + 1][A.first->from->idx][airp->idx];
                    Edge *e2 = task->canfromto[first + 1 + 1][airp->idx][A.second->to->idx];
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
                if (delta_cost <= 0 or swap_anyway(task, total_cost, delta_cost)) {
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
            {
                // --------------- BEGIN OF 3 SWAP --------------------

                // одна попытка поменять сразу три вершины
                int max_edge_id = sol.sequence.size(); // видимо первый не трогаем, а последний обрабатываем отдельно
                if (max_edge_id <= 5)
                    return sol;

                std::vector<int> edges_in_cicle = generate_k(3, max_edge_id - 1);
                // циклический обмен
                std::vector<std::pair<const Edge *, const Edge *> > chain, chain_new;
                chain_new.resize(3, {nullptr, nullptr});
                for (int g = 0; g < static_cast<int>(edges_in_cicle.size()); g++) {
                    chain.push_back({sol.sequence[edges_in_cicle[g]], sol.sequence[edges_in_cicle[g] + 1]});
                    assert(sol.sequence[edges_in_cicle[g]] != nullptr &&
                           sol.sequence[edges_in_cicle[g] + 1] != nullptr);
                }
                long long min_cost = COST_INF;
                long long delta_cost = 0;
                for (auto &triple : chain) {
                    delta_cost -= triple.first->cost + triple.second->cost;
                }
                vector<Airport *> mids;
                for (auto &triple : chain) {
                    mids.push_back(triple.first->to);
                }
                int need_to_solve = chain.size();
                for (int vid = 0; vid < static_cast<int>(chain.size()); ++vid) {
                    min_cost = COST_INF;
                    int vid_next = (vid + 1) % static_cast<int>(chain.size());
                    for (auto airp : task->zone_airports[mids[vid_next]->zone]) {
                        Edge *e1 = task->canfromto[edges_in_cicle[vid]][chain[vid].first->from->idx][airp->idx];
                        Edge *e2 = task->canfromto[edges_in_cicle[vid] + 1][airp->idx][chain[vid].second->to->idx];
                        if (e1 != nullptr && e2 != nullptr) {
                            long long cost = e1->cost + e2->cost;
                            if (min_cost > cost) {
                                min_cost = cost;
                                chain_new[vid] = {e1, e2};
                            }
                        }
                    }
                    if (min_cost != COST_INF)
                        need_to_solve--;
                    delta_cost += min_cost;
                }
                if (need_to_solve > 0) {
                    continue;
                    // не нашли
                }
                if (delta_cost <= 0 or swap_anyway(task, total_cost, delta_cost)) {
                    //  поменять ребра в sol
                    for (int vid = 0; vid < static_cast<int>(chain.size()); ++vid) {
                        assert (chain_new[vid].first != nullptr);
                        assert (chain_new[vid].second != nullptr);
                        sol.sequence[edges_in_cicle[vid]] = chain_new[vid].first;
                        sol.sequence[edges_in_cicle[vid] + 1] = chain_new[vid].second;
                    }
                    total_cost += delta_cost;
                }
                sol.score();
                if (sol.total_score < global_best_score) {
                    cerr << "CURRENT BEST GLOBAL SCORE (BY TRIPPLE CHANGE)" << sol.total_score << '\n';
                    global_best_score = sol.total_score;
                    global_best_sequence = sol.sequence;
                }
                // ------------------END OF 3 SWAP -------------------------
            }
        }
    }
    sol.sequence = move(global_best_sequence);
    sol.score();
    return sol;
}


Solution solve_local_search_3v(Assignment *task, Solution sol) {
    sol.score();
    long long total_cost = sol.total_score; // want to minimize
    const int MAX_ITER_INNER = 50000;
    const int MAX_ITER_OUTER = 10000000;
    long long COST_INF = 10000000000;

    //  const int MAX_REGION = 300;
    // preprocessing
    task->init_can_from_to();

    auto basic_seq = sol.sequence;
    auto global_best_sequence = sol.sequence;
    long long global_best_score = total_cost;
    for (int j = 0; j < MAX_ITER_OUTER && !task->ready_to_stop(); j++) {
        sol.sequence = basic_seq;
        for (int p = 0; p < MAX_ITER_INNER && !task->ready_to_stop(); p++) {
            //  выбираем пару объектов в цепочке
            int max_edge_id = sol.sequence.size(); // видимо первый не трогаем, а последний обрабатываем отдельно
            if (max_edge_id <= 5)
                return sol;

            std::vector<int> edges_in_cicle = generate_k(3, max_edge_id - 1);
            // циклический обмен
            std::vector<std::pair<const Edge *, const Edge *> > chain, chain_new;
            chain_new.resize(3, {nullptr, nullptr});
            for (int g = 0; g < static_cast<int>(edges_in_cicle.size()); g++) {
                chain.push_back({sol.sequence[edges_in_cicle[g]], sol.sequence[edges_in_cicle[g] + 1]});
                assert(sol.sequence[edges_in_cicle[g]] != nullptr && sol.sequence[edges_in_cicle[g] + 1] != nullptr);
            }
            long long min_cost = COST_INF;
            long long delta_cost = 0;
            for (auto & triple : chain) {
                delta_cost -= triple.first->cost + triple.second->cost;
            }
            vector<Airport *> mids;
            for (auto & triple : chain) {
                mids.push_back(triple.first->to);
            }
            int need_to_solve = chain.size();
            for (int vid = 0; vid < static_cast<int>(chain.size()); ++vid) {
                min_cost = COST_INF;
                int vid_next = (vid + 1) % static_cast<int>(chain.size());
                for (auto airp : task->zone_airports[mids[vid_next]->zone]) {
                    Edge *e1 = task->canfromto[edges_in_cicle[vid]][chain[vid].first->from->idx][airp->idx];
                    Edge *e2 = task->canfromto[edges_in_cicle[vid] + 1][airp->idx][chain[vid].second->to->idx];
                    if (e1 != nullptr && e2 != nullptr) {
                        long long cost = e1->cost + e2->cost;
                        if (min_cost > cost) {
                            min_cost = cost;
                            chain_new[vid] = {e1, e2};
                        }
                    }
                }
                if (min_cost != COST_INF)
                    need_to_solve--;
                delta_cost += min_cost;
            }
            if (need_to_solve > 0) {
                continue;
                // не нашли
            }
            if (delta_cost <= 0 or swap_anyway(task, total_cost, delta_cost)) {
                //  поменять ребра в sol
                for (int vid = 0; vid < static_cast<int>(chain.size()); ++vid) {
                    assert (chain_new[vid].first != nullptr);
                    assert (chain_new[vid].second != nullptr);
                    sol.sequence[edges_in_cicle[vid]] = chain_new[vid].first;
                    sol.sequence[edges_in_cicle[vid] + 1] = chain_new[vid].second;
                }
                total_cost += delta_cost;
            }
            sol.score();
            if (sol.total_score < global_best_score) {
                cerr << "CURRENT BEST GLOBAL SCORE " << sol.total_score << '\n';
                global_best_score = sol.total_score;
                global_best_sequence = sol.sequence;
            }
        }
    }
    sol.sequence = move(global_best_sequence);
    sol.score();
    return sol;
}
