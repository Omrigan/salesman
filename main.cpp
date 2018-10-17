#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <iterator>
#include <string>
using namespace std;

struct Edge{
    int f, t, d, c;
};
struct Vertex {
    int idx, zone;
};

struct Assignment {
    int N, start;
    vector<Vertex> vertices;
    vector<Edge> edges; 

    unordered_map<string, int> airport_to_idx;
    vector<string> idx_to_airport;

    vector<string> zones;

};



struct Solution {
    Assignment* task;
    vector<int> sequence;
    int total_score = 0;
    void score(){
        total_score = 0;
        for(int x : sequence){
            total_score+=task->edges[x].c;
        }
    }
    void print(){
        score();
        cout << total_score << endl;
        for(int i = 0; i < sequence.size(); ++i){
            Edge e = task->edges[sequence[i]];
            cout << task->idx_to_airport[e.f] << " " << task->idx_to_airport[e.t] << " "
            << i+1 << " " << e.c << endl;
        }
    }

};

Solution solve_simple(Assignment* task){
    Solution sol{.task = task};
    int current_place = task->start;
    int current_day = 1;
    vector<bool> visited(task->N);
    int visited_cnt = 1;
    visited[task->vertices[current_place].zone] = true;
    while(visited_cnt<task->N){
        for(int i = 0; i < task->edges.size();++i){
            // cerr << current_place;
            Edge e = task->edges[i];
            if(e.f==current_place and !visited[task->vertices[e.t].zone] and (e.d==0 or e.d==current_day)){
                sol.sequence.push_back(i);
                current_place = e.t;
                visited[task->vertices[current_place].zone] = true; 
                break;
            }
        }
        ++visited_cnt;
        ++current_day;
    }
    for(int i = 0; i < task->edges.size();++i){
        Edge e = task->edges[i];
        if(e.f==current_place and e.t==task->start){
            sol.sequence.push_back(i);
            break;
        }
    }

    return sol;
}

int main() {
    cerr << "Starting" << endl;
    string start_airport_str, input;
    Assignment task;
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
            if(task.airport_to_idx.find(item)==task.airport_to_idx.end()){
                task.airport_to_idx[item]=task.idx_to_airport.size();
                task.idx_to_airport.push_back(item);
            }     
            task.vertices.push_back({task.vertices.size(), i});
        
        }
    }
    // cerr << task.zones[0] << endl;
    cerr << "Vertices read" << endl;
    task.start = task.airport_to_idx[start_airport_str];
    while(!cin.eof()){
        string from, to;
        // cerr << from << to << endl;
        int d, c;
        cin >> from >> to >> d >> c;
        task.edges.push_back({
            task.airport_to_idx[from],
            task.airport_to_idx[to],
            d,c}
        );
    }
    Solution sol = solve_simple(&task);
    sol.print();
	return 0;
}