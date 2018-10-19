#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <iterator>
#include <string>
#include <chrono>
#include <functional>

using namespace std;

using Clock = chrono::steady_clock;
using Microseconds = chrono::microseconds;
using Time = Clock::time_point;


struct Edge;
struct Airport {
    int idx, zone;
    vector<Edge*> edges_from;
};

struct Edge{
    Airport *from, *to;
    int day, cost;
};

struct Assignment {

    Time start_time = Clock::now(), 
    finish_time;
    int kind = -1; // 0 - small, 1 - medium, 2 - large


    int N;
    Airport* start;
    vector<Airport> airports;
    vector<Edge> edges; 

    unordered_map<string, int> airport_name_to_idx;
    vector<string> idx_to_airport;

    vector<string> zones;

    

    void init(){
        for(int i = 0; i < edges.size(); ++i){
            edges[i].from->edges_from.push_back(&edges[i]);
        }


        if(N<=20){
            kind=1;
            finish_time = start_time + std::chrono::milliseconds(2700);
        } else if (N<=100){
            kind=2;
            finish_time = start_time + std::chrono::milliseconds(4700);
        } else{
            kind=3;
            finish_time = start_time + std::chrono::milliseconds(14700);
        }
    }

    bool ready_to_stop(){
        return Clock::now()>finish_time;
    }

};



struct Solution {
    Assignment* task;
    vector<Edge*> sequence;
    int total_score = 0;
    bool correct = false;
    void score(){
        total_score = 0;
        correct = sequence.size()==task->N;
        for(Edge* x : sequence){
            total_score+=x->cost;
        }
    }
    void print(){
        cout << total_score << endl;
        for(int i = 0; i < sequence.size(); ++i){
            Edge* e = sequence[i];
            cout << task->idx_to_airport[e->from->idx] << " " << task->idx_to_airport[e->to->idx] << " "
            << i+1 << " " << e->cost << endl;
        }
    }

};

Solution solve_simple(Assignment* task){
    Solution sol{.task = task};
    Airport* current_place = task->start;
    vector<bool> visited(task->N);
    visited[current_place->zone] = true;
    for(int current_day = 0; current_day<task->N; ++current_day){
        int limit = current_place->edges_from.size();
        if(limit!=0){
           
            int offset = rand() % limit;
            if(current_day==task->N-1)
            {
                visited[task->start->zone] = false;
            }
            for(int i = 0; i < limit;++i){
                int idx = (i+offset)%limit;
                Edge* e = current_place->edges_from[idx];
                if(!visited[e->to->zone] and (e->day==-1 or e->day==current_day)){
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
Solution run_cnt(function<Solution(Assignment*)> original, Assignment* task, int cnt){
    Solution best = original(task);
    for(int i = 1; i< cnt; ++i){
        Solution temp = original(task);
        temp.score();
        if(temp.correct and temp.total_score < best.total_score){
            cerr << "Improvement from "  << best.total_score << " to " << temp.total_score << endl;
            best = temp;
        }
    }
    return best;
}
Solution run_until_tl(function<Solution(Assignment*)> original, Assignment* task){
    Solution best = original(task);
    while(true){
        Solution temp = original(task);
        temp.score();
        if(temp.correct and temp.total_score < best.total_score){
            cerr << "Improvement from "  << best.total_score << " to " << temp.total_score << endl;
            best = temp;
        }
        #ifdef DEBUG
            break;
        #endif
        if(task->ready_to_stop()){
            break;
        }
    }
    return best;
}

int main() {

    Assignment task;

    srand(time(NULL));
   
    cerr << "Starting" << endl;
    string start_airport_str, input;
    cin >> task.N >> start_airport_str;
    getline(cin,input);
    // vector<vector<string>> airport_names;
    task.zones.resize(task.N);
    for(int i = 0; i<task.N; ++i){
        getline(cin, task.zones[i]);
        string airports_raw;
        getline(cin, airports_raw);
        istringstream iss(airports_raw);
        string item;
        while (getline(iss, item, ' ')) {
            if(task.airport_name_to_idx.find(item)==task.airport_name_to_idx.end()){
                task.airport_name_to_idx[item]=task.idx_to_airport.size();
                task.idx_to_airport.push_back(item);
            }     
            task.airports.push_back({task.airports.size(), i});
        
        }
    }
    // cerr << task.zones[0] << endl;
    cerr << "Airports read" << endl;
    task.start = &task.airports[task.airport_name_to_idx[start_airport_str]];
    while(!cin.eof()){
        string from, to;
        // cerr << from << to << endl;
        int day, cost;
        cin >> from >> to >> day >> cost;
        task.edges.push_back({
            &task.airports[task.airport_name_to_idx[from]],
            &task.airports[task.airport_name_to_idx[to]],
            day-1,cost}
        );
    }
    task.init();
    cerr << "Assignment initialised" << endl;

    // Solution sol = solve_simple(&task);
    Solution sol = run_until_tl(solve_simple,&task);
     if(!sol.correct){
        cerr << "SOLUTION INCORRECT!" << endl;
    }
    cerr << "Completed in: " << std::chrono::duration_cast<chrono::milliseconds>(Clock::now() - task.start_time).count() << endl;
    sol.score();
    sol.print();
	return 0;
}