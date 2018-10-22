#include "basic_structs.cpp" //nosubmit

static constexpr int RETRY_NUMBER = 20;

// returns false iff there is no more suitable edges
bool iterate_to_next_edge(const vector<bool>& visited, const vector<const Edge*>& edges, int& ind) {
    ind = min(ind + 1, static_cast<int>(edges.size()));
    while (ind < edges.size()) {
        if (!visited[edges[ind]->to->zone]) return true;
        ++ind;
    }
    return false;
}

int get_suitable_edges(const vector<bool>& visited, const Airport* airport, int day, int max_edge_ind) {
    int suitable_edges_cnt = 0;

    int ind = -1;
    while (iterate_to_next_edge(visited, airport->edges_from_by_day[day], ind)) {
        ++suitable_edges_cnt;
        if (suitable_edges_cnt == max_edge_ind) {
            return suitable_edges_cnt;
        }
    }
    ind = -1;
    while (iterate_to_next_edge(visited, airport->edges_from_by_day[0], ind)) {
        ++suitable_edges_cnt;
        if (suitable_edges_cnt == max_edge_ind) {
            return suitable_edges_cnt;
        }
    }
    return suitable_edges_cnt;
}

// really nasty
Edge const* get_suitable_edge(const vector<bool>& visited, const Airport* airport, int day, int ind) {
    int cur_ind_day = -1;
    int cur_ind_zero = -1;

    int edges_found = 0;

    iterate_to_next_edge(visited, airport->edges_from_by_day[day], cur_ind_day);
    iterate_to_next_edge(visited, airport->edges_from_by_day[0], cur_ind_zero);

    Edge const* cur_edge;

    while (edges_found < ind) {
        if (cur_ind_day >= airport->edges_from_by_day[day].size()) {
            assert(cur_ind_zero < airport->edges_from_by_day[0].size());
            cur_edge = airport->edges_from_by_day[0][cur_ind_zero];
            iterate_to_next_edge(visited, airport->edges_from_by_day[0], cur_ind_zero);
        } else {
            if (cur_ind_zero >= airport->edges_from_by_day[0].size()) {
                assert(cur_ind_day < airport->edges_from_by_day[day].size());
                cur_edge = airport->edges_from_by_day[day][cur_ind_day];
                iterate_to_next_edge(visited, airport->edges_from_by_day[day], cur_ind_day);
            } else {
                if (airport->edges_from_by_day[0][cur_ind_zero]->cost < airport->edges_from_by_day[day][cur_ind_day]->cost) {
                    cur_edge = airport->edges_from_by_day[0][cur_ind_zero];
                    iterate_to_next_edge(visited, airport->edges_from_by_day[0], cur_ind_zero);
                } else {
                    cur_edge = airport->edges_from_by_day[day][cur_ind_day];
                    iterate_to_next_edge(visited, airport->edges_from_by_day[day], cur_ind_day);
                }
            }
        }

        ++edges_found;    
    }

    assert(edges_found == ind);

    return cur_edge;
}

Edge const* get_next_edge(const Assignment* task, const vector<bool>& visited, const Airport* airport, int day) {
    int suitable_edges_cnt = get_suitable_edges(visited, airport, day, task->max_edge_index);
    if (!suitable_edges_cnt) return nullptr;

    int ind = rand() % min(task->max_edge_index, suitable_edges_cnt) + 1;
    return get_suitable_edge(visited, airport, day, ind);
} 

Solution greedy(const Assignment* task) {
    Solution solution{ .task = task };
    Airport* cur_airport = task->start;
    vector<bool> visited(task->N, false);
    visited[cur_airport->zone] = true;
    for(int cur_day = 1; cur_day < task->N; ++cur_day) {
        Edge const* next_edge = get_next_edge(task, visited, cur_airport, cur_day);

        if (next_edge == nullptr) {
            return Solution();
        }

        solution.sequence.push_back(next_edge);
        visited[next_edge->to->zone] = true;
        cur_airport = next_edge->to;
    }

    const Edge * next_edge = nullptr;
    for (const Edge* edge : cur_airport->edges_from) {
        if ((edge->day == 0 or edge->day == task->N) and
            edge->to->zone == task->start->zone) {
            if (next_edge == nullptr or next_edge->cost > edge->cost) {
                next_edge = edge;
            }
        }
    }
    if (next_edge == nullptr) {
        return Solution();
    }
    solution.sequence.push_back(next_edge);

    solution.score();
    return solution;
}
