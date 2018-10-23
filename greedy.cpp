#include "basic_structs.cpp" //nosubmit

struct GreedyManager {
    GreedyManager() = delete;

    GreedyManager(const Assignment* task_, int day_ = 1)
        : task(task_)
        , day(day_) {
        solution.task = task;
        airport = task->start;
        visited.assign(task->N, false);
        visited[airport->zone] = true;
    }
    
    Airport* airport;
    int day;
    vector<bool> visited;
    Solution solution;
    const Assignment* task;
};

// returns false iff there is no more suitable edges
bool iterate_to_next_edge(const vector<bool>& visited, const vector<const Edge*>& edges, int& ind) {
    ind = min(ind + 1, static_cast<int>(edges.size()));
    while (ind < edges.size()) {
        if (!visited[edges[ind]->to->zone]) return true;
        ++ind;
    }
    return false;
}

int get_suitable_edges(GreedyManager* mngr) {
    int suitable_edges_cnt = 0;

    int ind = -1;
    while (iterate_to_next_edge(mngr->visited, mngr->airport->edges_from_by_day[mngr->day], ind)) {
        ++suitable_edges_cnt;
        if (suitable_edges_cnt == mngr->task->max_edge_index) {
            return suitable_edges_cnt;
        }
    }
    ind = -1;
    while (iterate_to_next_edge(mngr->visited, mngr->airport->edges_from_by_day[0], ind)) {
        ++suitable_edges_cnt;
        if (suitable_edges_cnt == mngr->task->max_edge_index) {
            return suitable_edges_cnt;
        }
    }
    return suitable_edges_cnt;
}

// really nasty
Edge const* get_suitable_edge(GreedyManager* mngr, int ind) {
    int cur_ind_day = -1;
    int cur_ind_zero = -1;

    int edges_found = 0;

    iterate_to_next_edge(mngr->visited, mngr->airport->edges_from_by_day[mngr->day], cur_ind_day);
    iterate_to_next_edge(mngr->visited, mngr->airport->edges_from_by_day[0], cur_ind_zero);

    Edge const* cur_edge;

    while (edges_found < ind) {
        if (cur_ind_day >= mngr->airport->edges_from_by_day[mngr->day].size()) {
            assert(cur_ind_zero < mngr->airport->edges_from_by_day[0].size());
            cur_edge = mngr->airport->edges_from_by_day[0][cur_ind_zero];
            iterate_to_next_edge(mngr->visited, mngr->airport->edges_from_by_day[0], cur_ind_zero);
        } else {
            if (cur_ind_zero >= mngr->airport->edges_from_by_day[0].size()) {
                assert(cur_ind_day < mngr->airport->edges_from_by_day[mngr->day].size());
                cur_edge = mngr->airport->edges_from_by_day[mngr->day][cur_ind_day];
                iterate_to_next_edge(mngr->visited, mngr->airport->edges_from_by_day[mngr->day], cur_ind_day);
            } else {
                if (mngr->airport->edges_from_by_day[0][cur_ind_zero]->cost < 
                    mngr->airport->edges_from_by_day[mngr->day][cur_ind_day]->cost) {
                    cur_edge = mngr->airport->edges_from_by_day[0][cur_ind_zero];
                    iterate_to_next_edge(mngr->visited, mngr->airport->edges_from_by_day[0], cur_ind_zero);
                } else {
                    cur_edge = mngr->airport->edges_from_by_day[mngr->day][cur_ind_day];
                    iterate_to_next_edge(mngr->visited, mngr->airport->edges_from_by_day[mngr->day], cur_ind_day);
                }
            }
        }

        ++edges_found;    
    }

    assert(edges_found == ind);

    return cur_edge;
}

Edge const* get_next_edge(GreedyManager* mngr) {
    int suitable_edges_cnt = get_suitable_edges(mngr);
    if (!suitable_edges_cnt) return nullptr;

    int ind = rand() % min(mngr->task->max_edge_index, suitable_edges_cnt) + 1;
    if (mngr->day == mngr->task->N) {
        ind = 1;
    }
    return get_suitable_edge(mngr, ind);
} 

vector<const Edge*> get_greedy_path(GreedyManager* mngr) {
    vector<const Edge*> path_edges;
    for (; mngr->day <= mngr->task->N; ++mngr->day) {
        if (mngr->day == mngr->task->N) {
            mngr->visited[mngr->task->start->zone] = false;
        }

        Edge const* next_edge = get_next_edge(mngr);

        if (next_edge == nullptr) {
            return {};
        }

        path_edges.push_back(next_edge);
        mngr->visited[next_edge->to->zone] = true;
        mngr->airport = next_edge->to;
    }
    return path_edges;
}

Solution greedy(const Assignment* task) {
    GreedyManager mngr(task);
    /*
    Solution solution{ .task = task };
    Airport* airport = task->start;
    vector<bool> visited(task->N, false);
    visited[airport->zone] = true;
    */
    mngr.solution.sequence = get_greedy_path(&mngr);

    return mngr.solution;
}

Solution greedy_mcts(const Assignment* task) {
    Solution solution{ .task = task };
}
