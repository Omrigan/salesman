#include <numeric>

#include "basic_structs.cpp" //nosubmit

struct GreedyManager {
    GreedyManager() = delete;

    GreedyManager(const Assignment* task_, int day_ = 1)
        :  day(day_)
        , task(task_) {
        airport = task->start;
        visited.assign(task->N, false);
        visited[airport->zone] = true;
    }

    GreedyManager(const GreedyManager& other) = default;

    void make_step(const Edge* next_edge, vector<const Edge*>* solution_edges = nullptr) {
        if (solution_edges != nullptr) solution_edges->push_back(next_edge);
        ++next_edge->number_visited;
        visited[next_edge->to->zone] = true;
        airport = next_edge->to;
        ++day;
    }
    
    Airport* airport;
    int day;
    vector<bool> visited;
    const Assignment* task;
};

// it's assumed that vector with edges stays unchanged
struct SuitableEdgesIterator {
    SuitableEdgesIterator() = delete;
    SuitableEdgesIterator(const vector<const Edge*>& edges_zero_,
                          const vector<const Edge*>& edges_day_) 
        : edges_zero(&edges_zero_)
        , edges_day(&edges_day_)
        , ind_zero(-1)
        , ind_day(-1) {}

    // returns false iff there are no more suitable edges
    bool iterate_to_next_edge(const vector<bool>& visited, const vector<const Edge*>* edges, int& ind) {
        int edges_size = edges->size();
        ind = min(ind + 1, edges_size);
        while (ind < edges_size) {
            if (!visited[(*edges)[ind]->to->zone]) return true;
            ++ind;
        }
        return false;
    }

    void reset() {
        ind_zero = -1;
        ind_day = -1;
    }

    const Edge* get_next_suitable_edge(const vector<bool>& visited) {
        move_init(visited);

        if (!is_valid(ind_zero, edges_zero)) {
            if (!is_valid(ind_day, edges_day)) {
                return nullptr;
            } else {
                return get_next_indexed_edge(visited, edges_day, ind_day);
            }
        } else {
            if (!is_valid(ind_day, edges_day)) {
                return get_next_indexed_edge(visited, edges_zero, ind_zero);
            } else {
                if ((*edges_zero)[ind_zero]->cost < (*edges_day)[ind_day]->cost) {
                    return get_next_indexed_edge(visited, edges_zero, ind_zero);
                } else {
                    return get_next_indexed_edge(visited, edges_day, ind_day);
                }
            }
        }
    }

    const Edge* get_next_nth_suitable_edge(const vector<bool>& visited, int n) {
        const Edge* res = nullptr;
        for (int i = 0; i < n; ++i) {
            res = get_next_suitable_edge(visited);
        }
        return res;
    }

    vector<const Edge*> get_next_n_edges(const vector<bool>& visited, int n) {
        vector<const Edge*> res;
        for (int i = 0; i < n; ++i) {
            res.push_back(get_next_suitable_edge(visited));
        }
        return res;
    }

    // call reset() after calling this function
    int get_number_of_suitable_edges(const vector<bool>& visited, int threshold = -1) {
        reset();
        int res = 0;
        while (iterate_to_next_edge(visited, edges_zero, ind_zero)) {
            ++res;
            if (res >= threshold and threshold != -1) return res;
        }
        while (iterate_to_next_edge(visited, edges_day, ind_day)) {
            ++res;
            if (res >= threshold and threshold != -1) return res;
        }
        return res;
    }

    const Edge* get_least_visited(const vector<bool>& visited) {
        const Edge* cur_best = nullptr;
        int times_visited = -1;
        const Edge* tmp_edge = nullptr;
        while ((tmp_edge = get_next_suitable_edge(visited)) != nullptr) {
            if (!cur_best or (times_visited < cur_best->number_visited)) {
                cur_best = tmp_edge;
            }
        }
        return cur_best;
    }

    const vector<const Edge*>* edges_zero;
    const vector<const Edge*>* edges_day;
    int ind_zero;
    int ind_day;

private:
    void move_init(const vector<bool>& visited) {
        if (ind_zero == -1) {
            iterate_to_next_edge(visited, edges_zero, ind_zero);
        }
        if (ind_day == -1) {
            iterate_to_next_edge(visited, edges_day, ind_day);
        }
    }

    bool is_valid(int ind, const vector<const Edge*>* edges) {
        return ind < static_cast<int>(edges->size());
    }

    const Edge* get_next_indexed_edge(const vector<bool>& visited, 
                                      const vector<const Edge*>* edges, 
                                      int& ind) {
        const Edge* ret_edge = (*edges)[ind];
        iterate_to_next_edge(visited, edges, ind);
        return ret_edge;
    }
};

const Edge* get_next_edge_random(GreedyManager* mngr) {
    SuitableEdgesIterator it(mngr->airport->edges_from_by_day[0], mngr->airport->edges_from_by_day[mngr->day]);
    int suitable_edges_cnt = it.get_number_of_suitable_edges(mngr->visited, mngr->task->max_edge_index);
    it.reset();
    if (!suitable_edges_cnt) return nullptr;

    int ind = RandomGenerator::get_rand_int() % min(mngr->task->max_edge_index, suitable_edges_cnt) + 1;
    if (mngr->day == mngr->task->N) {
        ind = 1;
    }
    return it.get_next_nth_suitable_edge(mngr->visited, ind);
}

const Edge* get_random_edge_weighted(GreedyManager* mngr, const vector<const Edge*>& suitable_edges) {
    if (mngr->day == mngr->task->N) {
        return suitable_edges.front();
    }

    vector<double> edges_weights;
    transform(suitable_edges.begin(), suitable_edges.end(), back_inserter(edges_weights), 
        [&suitable_edges](const Edge* a) {
        return sqrt(suitable_edges.front()->cost / static_cast<double>(a->cost));
    });

    discrete_distribution<int> edges_costs_distr(edges_weights.begin(), edges_weights.end()); 

    // remove .at when release
    const Edge* next_edge = suitable_edges.at(edges_costs_distr(RandomGenerator::gen_rand));
    assert(next_edge != nullptr); 
    return next_edge;
}

const Edge* get_next_edge_weighted(GreedyManager* mngr) {
    SuitableEdgesIterator it(mngr->airport->edges_from_by_day[0], mngr->airport->edges_from_by_day[mngr->day]);
    int suitable_edges_cnt = it.get_number_of_suitable_edges(mngr->visited, mngr->task->max_edge_index);
    it.reset();
    if (!suitable_edges_cnt) return nullptr;

    vector<const Edge*> suitable_edges = it.get_next_n_edges(mngr->visited, min(mngr->task->max_edge_index, suitable_edges_cnt));
    it.reset();

    assert(static_cast<int>(suitable_edges.size()) == suitable_edges_cnt);

    return get_random_edge_weighted(mngr, suitable_edges);
}

const Edge* get_least_visited_edge(GreedyManager *mngr) {
    SuitableEdgesIterator it(mngr->airport->edges_from_by_day[0], mngr->airport->edges_from_by_day[mngr->day]);
    const Edge* least_visited_edge = it.get_least_visited(mngr->visited);
    return least_visited_edge; 
}

// return empty vector iff no path found
vector<const Edge*> get_greedy_path(GreedyManager* mngr) {
    vector<const Edge*> path_edges;
    for (; mngr->day <= mngr->task->N;) {
        if (mngr->day == mngr->task->N) {
            mngr->visited[mngr->task->start->zone] = false;
        }

        Edge const* next_edge;
        // we can try 'get_least_visited_edge' here
        if (RandomGenerator::get_rand_prob() > mngr->task->least_visited_edge_prob) {
            if (RandomGenerator::get_rand_prob() > mngr->task->weighted_random) {
                next_edge = get_next_edge_random(mngr); 
            } else {
                next_edge = get_next_edge_weighted(mngr);
            }
        } else {
            next_edge = get_least_visited_edge(mngr);
        }

        if (next_edge == nullptr) {
            return {};
        }

        mngr->make_step(next_edge, &path_edges);
    }
    return path_edges;
}

Solution greedy(const Assignment* task) {
    GreedyManager mngr(task);
    Solution solution(task);
    solution.sequence = get_greedy_path(&mngr);
    return solution;
}

Solution greedy_mcts(const Assignment* task) {
    GreedyManager mngr(task);
    Solution solution(task);
    for (; mngr.day <= mngr.task->N;) {
        if (mngr.day == mngr.task->N) {
            mngr.visited[mngr.task->start->zone] = false;
        }

        int best_result = 0;
        const Edge* next_edge = nullptr;

        SuitableEdgesIterator it(mngr.airport->edges_from_by_day[0], mngr.airport->edges_from_by_day[mngr.day]);
        int suitable_edges_cnt = it.get_number_of_suitable_edges(mngr.visited);
        it.reset();

        for (int i = 0; i < min(task->max_edge_index, suitable_edges_cnt); ++i) {
            const Edge* next_edge_tmp = it.get_next_suitable_edge(mngr.visited);

            assert(next_edge_tmp != nullptr);

            for (int j = 0; j < MAX_ATTEMPT_MCTS_CNT; ++j) {
                GreedyManager mngr_tmp(mngr);

                mngr_tmp.make_step(next_edge_tmp);

                vector<const Edge*> cur_path = get_greedy_path(&mngr_tmp);

                long long cur_result = accumulate(cur_path.begin(), cur_path.end(), next_edge_tmp->cost, [](int sum, const Edge* a) {
                    return sum + a->cost;
                });

                if ((!cur_path.empty() or mngr.day == mngr.task->N) and
                    (next_edge == nullptr or best_result > cur_result)) {
                    best_result = cur_result;
                    next_edge = next_edge_tmp;
                }
            }
        }

        if (next_edge == nullptr) {
            return Solution();
        }

        mngr.make_step(next_edge, &solution.sequence);
    }

    return solution;
}
