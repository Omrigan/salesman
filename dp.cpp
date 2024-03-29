#include "basic_structs.cpp" //nosubmit

bool distance_cmp(int a, int b) {
    if (a == -1) {
        return false;
    } else {
        if (b == -1) {
            return true;
        }
        return a < b;
    }
}

vector<int> get_zone_order(const Assignment* task) {
    vector<int> zone_order;
    for (int i = 0; i < task->N; ++i) {
        if (i != task->start->zone) zone_order.push_back(i);
    }
    shuffle(zone_order.begin(), zone_order.end(), RandomGenerator::gen_rand);
    zone_order.push_back(task->start->zone);
    return zone_order;
}

int max_size(const vector<vector<Airport*>>& v) {
    int max_size = 0;
    for (const vector<Airport*> a : v) {
        if (max_size < static_cast<int>(a.size())) max_size = a.size();
    }
    return max_size;
}

vector<const Edge*> get_solution_sequence(const vector<vector<const Edge*>> dp_restore, int local_idx, int day) {
    vector<const Edge*> result;
    while (day > 0) {
        const Edge* cur_edge = dp_restore[day][local_idx];
        result.push_back(cur_edge);
        local_idx = cur_edge->from->local_idx;
        --day;
    }
    reverse(result.begin(), result.end());
    return result;
}

Solution dp_construct_solution_from(const Assignment* task, const vector<vector<const Edge*>> dp_restore, int local_idx) {
    Solution solution(task);
    solution.sequence = get_solution_sequence(dp_restore, local_idx, task->N);
    return solution;
}

// for debug purposes only
static int max_day = 0;

void recalc_dp(const Assignment* task, 
               vector<vector<int>>& best_distance,
               vector<vector<const Edge*>>& dp_restore, 
               const int prev_zone,
               const int zone,
               const int day,
               const int dp_day,
               bool& made_relaxation) {
    for (int airport_idx = 0; airport_idx < static_cast<int>(task->zone_airports[prev_zone].size()); ++airport_idx) {
        if (best_distance[0][airport_idx] != -1) {
            const Airport* prev_airport = task->zone_airports[prev_zone][airport_idx];
            for (const Edge* edge : prev_airport->edges_from) {
                if ((task->max_edge_cost == -1 or edge->cost < task->max_edge_cost) and
                    (edge->day == day or edge->day == 0) and
                    edge->to->zone == zone and
                    (best_distance[1][edge->to->local_idx] == -1 or
                    best_distance[1][edge->to->local_idx] > best_distance[0][edge->from->local_idx] + edge->cost)) {
                    best_distance[1][edge->to->local_idx] = best_distance[0][edge->from->local_idx] + edge->cost;
                    dp_restore[dp_day][edge->to->local_idx] = edge;
                    made_relaxation = true;
                }
            }
        }
    }
}

Solution fixed_zone_order_dp(const Assignment* task) {
    vector<int> zone_order = get_zone_order(task);

    int max_zone_size = max_size(task->zone_airports);

    // if an airport is unreachable, then 
    // the corresponding best_distance value is -1 
    vector<vector<int>> best_distance(2, vector<int>(max_zone_size, -1));
    best_distance[0][task->start->local_idx] = 0;

    // days are enumerate from 1
    // just like the edge's days
    vector<vector<const Edge*>> dp_restore(task->N + 1, vector<const Edge*>(max_zone_size, nullptr));

    int day = 1;
    int prev_zone = task->start->zone;
    int reshuffle_attempts = RESHUFFLE_ATTEMPTS;
    for (int zone_ind = 0; zone_ind < task->N; ++zone_ind) {
        int zone = zone_order[zone_ind];

        best_distance[1].assign(best_distance[1].size(), -1);

        bool made_relaxation = false;

        recalc_dp(task, best_distance, dp_restore, prev_zone, zone, day, day, made_relaxation);

        if (!made_relaxation) {
            --reshuffle_attempts;
            if (!reshuffle_attempts or zone_ind == task->N - 1) {
                return Solution();
            }
            shuffle(zone_order.begin() + zone_ind, zone_order.end() - 1, RandomGenerator::gen_rand);
            --zone_ind;
        } else {
            reshuffle_attempts = RESHUFFLE_ATTEMPTS;
            ++day;
            max_day = max(max_day, day);
            swap(best_distance[0], best_distance[1]);
            prev_zone = zone;
        }
    }

    auto best_final_distance = min_element(best_distance[0].begin(), best_distance[0].end(), distance_cmp);
    if (*best_final_distance == -1) {
        return Solution();
    } else {
        return dp_construct_solution_from(task, dp_restore, best_final_distance - best_distance[0].begin());
    }
}

int get_best_available_zone(const Assignment* task,
                            const vector<int>& cur_distances,
                            const set<int>& visited_zones,
                            int prev_zone,
                            int day) {
    set<int> new_available_zones;

    for (int prev_airport = 0; prev_airport < static_cast<int>(task->zone_airports[prev_zone].size()); ++prev_airport) {
        if (cur_distances[prev_airport] != -1) {
            for (const Edge* edge : task->zone_airports[prev_zone][prev_airport]->edges_from) {
                if ((task->max_edge_cost == -1 or edge->cost <= task->max_edge_cost) and
                    (edge->day == day or edge->day == 0) and !visited_zones.count(edge->to->zone)) {
                    assert(edge->from->local_idx == prev_airport);
                    new_available_zones.insert(edge->to->zone);
                }
            }
        }
    }

    if (new_available_zones.empty()) {
        return -1;
    } else {
        // rewrite this >_<
        int zone_ind = RandomGenerator::get_rand_int() % new_available_zones.size();
        auto zone_it = new_available_zones.begin();
        while (zone_ind) {
            ++zone_it;
            --zone_ind;
        }
        return *zone_it;
    }
}

Solution dynamic_zone_order_dp(const Assignment* task) {
    int max_zone_size = max_size(task->zone_airports);
    
    // if an airport is unreachable, then 
    // the corresponding best_distance value is -1 
    vector<vector<int>> best_distance(2, vector<int>(max_zone_size, -1));
    best_distance[0][task->start->local_idx] = 0;

    // days are enumerate from 1
    // just like the edge's days
    vector<vector<const Edge*>> dp_restore(task->N + 1, vector<const Edge*>(max_zone_size, nullptr));

    set<int> visited_zones;
    visited_zones.insert(task->start->zone);
    int prev_zone = task->start->zone;
    for (int day = 1; day <= task->N; ++day) {
        best_distance[1].assign(best_distance[1].size(), -1);

        if (day == task->N) {
            visited_zones.erase(task->start->zone);
        }

        int zone = get_best_available_zone(task, best_distance[0], visited_zones, prev_zone, day);

        if (zone == -1) {
            return Solution();
        }

        bool made_relaxation = false;

        recalc_dp(task, best_distance, dp_restore, prev_zone, zone, day, day, made_relaxation);

        if (!made_relaxation) {
            return Solution();
        }

        visited_zones.insert(zone);
        prev_zone = zone;

        swap(best_distance[0], best_distance[1]);
    }

    auto best_final_distance = min_element(best_distance[0].begin(), best_distance[0].end(), distance_cmp);
    if (*best_final_distance == -1) {
        return Solution();
    } else {
        return dp_construct_solution_from(task, dp_restore, best_final_distance - best_distance[0].begin());
    }
}
