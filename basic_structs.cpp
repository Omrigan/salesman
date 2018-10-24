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


using namespace std;

using Clock = chrono::steady_clock;
using Microseconds = chrono::microseconds;
using Time = Clock::time_point;

#ifndef BASIC_STRUCTS
#define BASIC_STRUCTS 1

static constexpr int MAX_AIRPORT = 300 + 12;
static constexpr int RESHUFFLE_ATTEMPTS = 112;
static constexpr int MAX_ATTEMPT_EDGES_COST = 112;
static constexpr int MAX_ATTEMPT_EDGES_CNT = 512;

// yummy
int64_t get_time_in_ms(Time time) {
    return chrono::duration_cast<chrono::milliseconds>(chrono::time_point_cast<chrono::milliseconds>(time).time_since_epoch()).count();
}

struct Edge;

struct Airport {
    Airport() = default;

    Airport(int idx_, int zone_, int local_idx_)
        : idx(idx_)
        , zone(zone_)
        , local_idx(local_idx_) {}

    int idx, zone;
    int local_idx;
    vector<Edge*> edges_from;
    vector<vector<const Edge*>> edges_from_by_day;
};

struct Edge {
    Airport* from;
    Airport* to;
    int day, cost;

    bool operator < (const Edge& other) const {
        return cost < other.cost;
    }
};

struct Assignment {
    Assignment() = default;

    // compiler says that it's better not to inline destructor
    // 
    ~Assignment();

    Time start_time = Clock::now();
    Time finish_time = Clock::now();
    int64_t start_time_long = 0;
    int64_t finish_time_long = 0;
    int kind = -1; // 0 - small, 1 - medium, 2 - large
    int N;
    Airport* start;
    vector<Airport> airports;
    vector<Edge> edges; 
    unordered_map<string, int> airport_name_to_idx;
    vector<string> idx_to_airport;
    vector<string> zones;
    vector<vector<Airport*>> zone_airports;
    int max_edge_cost = -1;
    int max_edge_index = 22;

    void init() {
        for (Airport& airport : airports) {	
            airport.edges_from_by_day.resize(N + 1);	
        }

        for (int i = 0; i < static_cast<int>(edges.size()); ++i) {
            edges[i].from->edges_from.push_back(&edges[i]);
            edges[i].from->edges_from_by_day[edges[i].day].push_back(&edges[i]);
        }

        for (Airport& airport : airports) {	
            for (vector<const Edge*>& airport_edges : airport.edges_from_by_day) {	
                sort(airport_edges.begin(), airport_edges.end(), [](const Edge* a, const Edge* b) {	
                    return a->cost < b->cost;	
                });	
            }	
        }

        if (N <= 20) { 
            kind = 1;
            finish_time = start_time + std::chrono::milliseconds(2700);
        } else if (N <= 100) {
            kind = 2;
            finish_time = start_time + std::chrono::milliseconds(4700);
        } else {
            kind = 3;
            finish_time = start_time + std::chrono::milliseconds(14000);
        }

        start_time_long = get_time_in_ms(start_time);
        finish_time_long = get_time_in_ms(finish_time);
    }

    bool ready_to_stop() {
        return Clock::now() > finish_time;
    }
};

Assignment::~Assignment() = default;

struct Solution {
    Solution() = default;
    
    Solution (const Assignment* task_) : task(task_) {}

    const Assignment* task;
    vector<const Edge*> sequence;
    int total_score = 0;
    bool correct = false;

    void score() {
        total_score = 0;
        if (task != nullptr) {
            correct = (static_cast<int>(sequence.size()) == task->N);
            for(const Edge* x : sequence) {
                total_score += x->cost;
            }
        }
    }

    void print() {
        cout << total_score << endl;
        for(int i = 0; i < static_cast<int>(sequence.size()); ++i) {
            const Edge* e = sequence[i];
            cout << task->idx_to_airport[e->from->idx] << " " << task->idx_to_airport[e->to->idx] << " "
                 << i + 1 << " " << e->cost << endl;
        }
    }

};

#endif
