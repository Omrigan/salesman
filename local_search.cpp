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

#include "basic_structs.cpp" //nosubmit
#include "dp.cpp" //nosubmit

double get_temp(const Assignment* task) {
    double time_elapsed = double(get_time_in_ms(Clock::now()) - task->start_time_long) / task->time_to_live;
    return 1 - time_elapsed;
}


bool swap_anyway(const Assignment* task, int total_cost, int delta_cost) {
    if (task->use_random_swaps) {
        double temp = get_temp(task);
        double prob;
        // assert(total_cost>0);
        if(!task->use_experimental_temp){
            prob =  temp * (total_cost / (10000 * static_cast<double>(delta_cost))); 
        } else{
            prob = exp(-10*(double(delta_cost))/(total_cost*temp));
            // prob =  exp(1/( (double) -delta_cost) * temp));

        }
        // cerr << "Prob: " << prob << endl;
        return prob > RandomGenerator::get_rand_prob();
    }
    return false;
}
int random(int a, int b) {
    if (b <= a)
        cerr << "INVALID ARGUMENT\n";
    return RandomGenerator::get_rand_int() % (b - a) + a;
}

struct IterEdges {
    IterEdges(const Solution* sol_) : sol(sol_) {};
    //  может либо возвращать рандомные ребра, либо сразу все, по которым надо пройтись
    std::vector<std::vector<int> > generate_all() {
        //  for local_solve only;
        //  для local_solve3opt - слишком долго
        std::vector<std::vector<int> > tries;
        for (int first = 0; first < static_cast<int>(sol->sequence.size()) - 3; first++) {
            for (int second = first + 2; second < static_cast<int>(sol->sequence.size()) - 1; second++) {
                tries.push_back({first, second});
            }
        }
        shuffle(tries.begin(), tries.end(), RandomGenerator::gen_rand);
        return tries;
    }
    
    vector<int> generate_k(int k) {
        assert(static_cast<int>(sol->sequence.size()) >= 2 * k);
        
        int module = sol->sequence.size() - k;
        set<int> distinct_indices;
        for (int i = 0; i < k; ++i) {
            int cur_num = RandomGenerator::get_rand_int() % module;
            while (distinct_indices.count(cur_num)) {
                cur_num = RandomGenerator::get_rand_int() % module;
            }
            distinct_indices.insert(cur_num);
        }

        vector<int> result;
        copy(distinct_indices.begin(), distinct_indices.end(), back_inserter(result)); 
        for (int i = 0; i < static_cast<int>(result.size()); ++i) {
            result[i] += i;
        }

        return result;
    }

    const Solution* sol;
};

struct LocalManager {
    LocalManager() = delete;

    LocalManager(const Assignment* task_, Solution* sol_)
            : task(task_)
            , sol(sol_) {
    }

    LocalManager(const LocalManager& other) = default;

    void local_step(vector<int> edges_in_cycle_) {
        // edges_in_cycle: array of indices of edges to a vertex that is to be swaped.
        // works for k-opt.
        edges_in_cycle = std::move(edges_in_cycle_);
        std::vector<std::pair<const Edge*, const Edge*> > chain, chain_new;
        chain_new.resize(edges_in_cycle.size(), {nullptr, nullptr});
        for (int g = 0; g < static_cast<int>(edges_in_cycle.size()); g++) {
            chain.push_back({sol->sequence[edges_in_cycle[g]], sol->sequence[edges_in_cycle[g] + 1]});
            assert(sol->sequence[edges_in_cycle[g]] != nullptr && sol->sequence[edges_in_cycle[g] + 1] != nullptr);
        }
        long long min_cost = COST_INF;
        for (auto& triple : chain) {
            delta_cost -= triple.first->cost + triple.second->cost;
        }
        vector<Airport*> mids;
        for (auto& triple : chain) {
            mids.push_back(triple.first->to);
        }
        int need_to_solve = static_cast<int>(chain.size());
        for (int vid = 0; vid < static_cast<int>(chain.size()); ++vid) {
            min_cost = COST_INF;
            int vid_next = (vid + 1) % static_cast<int>(chain.size());
            for (auto airp : task->zone_airports[mids[vid_next]->zone]) {
                Edge* e1 = task->canfromto[edges_in_cycle[vid] + 1][chain[vid].first->from->idx][airp->idx];
                Edge* e2 = task->canfromto[edges_in_cycle[vid] + 2][airp->idx][chain[vid].second->to->idx];
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
            chain_found = chain;
            delta_cost = 0;
            return;
            // не нашли
        }
        this->chain_found = chain_new;
        was_any_change_found = 1;
    }

    void move() {
        if (!was_any_change_found) {
            return;
        }
        //  поменять ребра в sol
        for (int vid = 0; vid < static_cast<int>(chain_found.size()); ++vid) {
            assert (chain_found[vid].first != nullptr);
            assert (chain_found[vid].second != nullptr);
            sol->sequence[edges_in_cycle[vid]] = chain_found[vid].first;
            sol->sequence[edges_in_cycle[vid] + 1] = chain_found[vid].second;
        }
        
    }

    vector<int> edges_in_cycle;
    std::vector<std::pair<const Edge*, const Edge*> > chain_found;
    const Assignment* task;
    int was_any_change_found = 0;
    long long delta_cost = 0;
    long long COST_INF = LLONG_MAX;
    Solution* sol;
};

Solution solve_local_search_3v(Assignment* task, Solution sol) {
    sol.score();
    long long total_cost = sol.total_score; // want to minimize
    const int MAX_ITER_INNER = 50;
    const int MAX_ITER_OUTER = 10000000;
    const int OPT_TYPE = 3;

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
            if (max_edge_id <= 10)
                return sol;
            LocalManager manager(task, &sol);
            IterEdges ite(&sol);
            std::vector<int> edges_in_cycle = ite.generate_k(OPT_TYPE);
            manager.local_step(edges_in_cycle);
            // which vertex we will move;
            if (manager.delta_cost <= 0 or swap_anyway(task, total_cost, manager.delta_cost)) {
                manager.move();
                total_cost += manager.delta_cost;
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

Solution solve_local_search(Assignment* task, Solution sol) {
    sol.score();
    long long total_cost = sol.total_score; // want to minimize
    const int MAX_ITER_INNER = 50;
    const int MAX_ITER_OUTER = 10000000;
    // const int OPT_TYPE = 2;

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
            if (max_edge_id <= 10)
                return sol;
            LocalManager manager(task, &sol);
            IterEdges ite(&sol);
            std::vector<std::vector<int> > array_edges_in_cycle = ite.generate_all();
            for (std::vector<int>& edges_in_cycle : array_edges_in_cycle) {
                manager.local_step(edges_in_cycle);
                // which vertex we will move;
                if (manager.delta_cost <= 0 or swap_anyway(task, total_cost, manager.delta_cost)) {
                    manager.move();
                    total_cost += manager.delta_cost;
                }
            }
            // we probably don't need this, it's scored just fine
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

vector<int> generate_k(int n, int k) {
    if (n <= 2 * k) return {};
    
    int module = n - k;
    set<int> distinct_indices;
    for (int i = 0; i < k; ++i) {
        int cur_num = RandomGenerator::get_rand_int() % module;
        while (distinct_indices.count(cur_num)) {
            cur_num = RandomGenerator::get_rand_int() % module;
        }
        distinct_indices.insert(cur_num);
    }

    vector<int> result;
    copy(distinct_indices.begin(), distinct_indices.end(), back_inserter(result)); 
    for (int i = 0; i < static_cast<int>(result.size()); ++i) {
        result[i] += i;
    }

    return result;
}

struct ChainSwapper {
    void do_swap(Solution& sol) {
        if (!found) {
            return;
        }
        // swap sol edges
        for (int vid = 0; vid < static_cast<int>(new_chain.size()); ++vid) {
            assert(new_chain[vid].first != nullptr);
            assert(new_chain[vid].second != nullptr);
            sol.sequence[old_chain_indices[vid]] = new_chain[vid].first;
            sol.sequence[old_chain_indices[vid] + 1] = new_chain[vid].second;
        }
        sol.total_score += delta_cost;
    }

    bool found = false;
    long long delta_cost = 0;
    long long total_cost = 0;
    vector<int> old_chain_indices;
    vector<pair<const Edge*, const Edge*>> new_chain;
};

ChainSwapper swap_chains_step(const Assignment* task, const Solution& sol, vector<int> edges_in_cycle) {
    // edges_in_cycle: array of indices of edges to a vertex that is to be swaped.
    // works for k-opt.
    ChainSwapper result_chain;
    result_chain.total_cost = sol.total_score;

    vector<pair<const Edge*, const Edge*>> chain, chain_new;
    chain_new.resize(edges_in_cycle.size(), {nullptr, nullptr});
    for (int g = 0; g < static_cast<int>(edges_in_cycle.size()); g++) {
        chain.push_back({sol.sequence[edges_in_cycle[g]], sol.sequence[edges_in_cycle[g] + 1]});
        assert(sol.sequence[edges_in_cycle[g]] != nullptr && sol.sequence[edges_in_cycle[g] + 1] != nullptr);
    }
    long long min_cost = LLONG_MAX;
    for (auto& triple : chain) {
        result_chain.delta_cost -= triple.first->cost + triple.second->cost;
    }
    vector<Airport*> mids;
    for (auto& triple : chain) {
        mids.push_back(triple.first->to);
    }
    int need_to_solve = static_cast<int>(chain.size());
    for (int vid = 0; vid < static_cast<int>(chain.size()); ++vid) {
        min_cost = LLONG_MAX;
        int vid_next = (vid + 1) % static_cast<int>(chain.size());
        for (auto airp : task->zone_airports[mids[vid_next]->zone]) {
            Edge* e1 = task->canfromto[edges_in_cycle[vid] + 1][chain[vid].first->from->idx][airp->idx];
            Edge* e2 = task->canfromto[edges_in_cycle[vid] + 2][airp->idx][chain[vid].second->to->idx];
            if (e1 != nullptr && e2 != nullptr) {
                long long cost = e1->cost + e2->cost;
                if (min_cost > cost) {
                    min_cost = cost;
                    chain_new[vid] = {e1, e2};
                }
            }
        }
        if (min_cost == LLONG_MAX) break;
        --need_to_solve;
        result_chain.delta_cost += min_cost;
    }

    // chain can't be built
    if (need_to_solve > 0) {
        result_chain.found = false;
    } else {
        result_chain.found = true;
        result_chain.old_chain_indices = move(edges_in_cycle);
        result_chain.new_chain = move(chain_new);
    }

    return result_chain;
}

Solution swap_chains(Assignment* task, Solution sol, vector<int> edges_indices) {
    if (edges_indices.empty()) return sol;
    ChainSwapper chain_swapper = swap_chains_step(task, sol, move(edges_indices));

    if (chain_swapper.delta_cost <= 0 or swap_anyway(task, chain_swapper.total_cost, chain_swapper.delta_cost)) {
        chain_swapper.do_swap(sol);
    }

    return sol;
}

Solution swap_chains_2v(Assignment* task, Solution sol) {
    return swap_chains(task, move(sol), generate_k(sol.sequence.size(), 2));
}

Solution swap_chains_3v(Assignment* task, Solution sol) {
    return swap_chains(task, move(sol), generate_k(sol.sequence.size(), 3));
}

Solution apply_all_swaps_2v(Assignment* task, Solution sol) {
    int n = sol.sequence.size();
    vector<vector<int>> all_indices;
    all_indices.reserve(n * n);
    for (int v = 0; v < n - 3; ++v) {
        for (int u = v + 2; u < n - 1; ++u) {
            all_indices.push_back({ v, u });
        }
    }
    shuffle(all_indices.begin(), all_indices.end(), RandomGenerator::gen_rand);
    for (vector<int>& v_ind : all_indices) {
        sol = swap_chains(task, move(sol), move(v_ind));
    }
    return sol;
}

Solution swap_adjacent_vertexes(Assignment* task, Solution sol) {
    int sol_size = sol.sequence.size();
    if (sol_size <= 3) return sol;
    int v_ind_start = RandomGenerator::get_rand_int() % (sol_size - 3);
    int max_v_ind_start = sol_size - 4;

    const Edge* e1 = sol.sequence[v_ind_start];
    const Edge* e2 = sol.sequence[v_ind_start + 1];
    const Edge* e3 = sol.sequence[v_ind_start + 2];
    
    int max_zone_size = max_size(task->zone_airports);

    vector<vector<int>> best_distance(2, vector<int>(max_zone_size, -1));
    best_distance[0][e1->from->local_idx] = 0;

    vector<vector<const Edge*>> dp_restore(4, vector<const Edge*>(max_zone_size, nullptr));

    int prev_zone = e1->from->zone;
    int day = v_ind_start + 1;
    int dp_day = 1;

    for (int zone : {e3->from->zone, e2->from->zone, e3->to->zone}) {
        best_distance[1].assign(best_distance[1].size(), -1);

        bool made_relaxation = false;

        recalc_dp(task, best_distance, dp_restore, prev_zone, zone, day, dp_day, made_relaxation);

        if (!made_relaxation) {
            return sol;
        }

        ++day;
        ++dp_day;
        swap(best_distance[0], best_distance[1]);
        prev_zone = zone;
    }

    vector<const Edge*> new_chain;
    if (v_ind_start == max_v_ind_start) {
        auto best_final_distance = min_element(best_distance[0].begin(), best_distance[0].end(), distance_cmp);
        if (*best_final_distance == -1) return sol;
        new_chain = get_solution_sequence(dp_restore, best_final_distance - best_distance[0].begin(), 3);
    } else {
        if (best_distance[0][e3->to->local_idx] == -1) return sol;
        new_chain = get_solution_sequence(dp_restore, e3->to->local_idx, 3);
    }

    int delta_cost = accumulate(new_chain.begin(), new_chain.end(), 0, [](int sum, const Edge* a) { return a->cost + sum; }) 
                     - (e1->cost + e2->cost + e3->cost);

    if (delta_cost <= 0 or swap_anyway(task, sol.total_score, delta_cost)) {
        int old_ind = v_ind_start;
        for (const Edge* edge : new_chain) {
            sol.sequence[old_ind] = move(edge);
            ++old_ind;
        }
        sol.total_score += delta_cost;
    }
    return sol;
}

struct LocalOptimizeManager {
    static vector<function<Solution(Assignment*, Solution)>> optimizations;

    // we assume that sol is correctly scored
    // before calling this
    static Solution apply_random_optimization(Assignment* task, Solution sol) {
        double n = static_cast<double>(sol.sequence.size());
        discrete_distribution<int> distribution = { n, n, 1 };
        task->init_can_from_to();
        auto func_optimize = optimizations[distribution(RandomGenerator::gen_rand)];
        sol = func_optimize(task, move(sol));
        return sol;
    }
};

vector<function<Solution(Assignment*, Solution)>> LocalOptimizeManager::optimizations = {
    swap_chains_2v,
    swap_chains_3v,
    apply_all_swaps_2v
    // swap_adjacent_vertexes
};
