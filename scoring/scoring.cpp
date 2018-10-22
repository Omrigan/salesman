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
#include <fstream>
#include <map>

using namespace std;

// TODO: unify variables namestyle
// TODO: use better random

using Clock = chrono::steady_clock;
using Microseconds = chrono::microseconds;
using Time = Clock::time_point;
vector<string> tests = {"public1.in", "public3.in"};
string test_folder = "tests";

using statistics = map<string, map<string,double>>;

void dump_statistics(const statistics& data){
    ofstream stats_file("scoring/stats.txt");
    stats_file << data.size() << endl;
    for(auto& run : data){
        stats_file << run.first << " " << run.second.size() << endl;
        for(auto& test : run.second){
            stats_file << test.first << " " << test.second << endl;
        }
        stats_file << endl;
    }
}

statistics  load_statistics(){
    statistics result;
    ifstream stats_file("scoring/stats.txt");
    int n;
    stats_file>>n;
    for(size_t i = 0; i < n; i++)
    {   
        string name, test;
        int m;
        stats_file >> name >> m;
        for(size_t j = 0; j < m; j++)
        {   
            stats_file >> test;
            stats_file >> result[name][test];

        }
    }
    return result;
}



void score(statistics* stats, string name){
    
    for(auto& test_name : tests){
        string cmd = "cat " + test_folder + "/" + test_name + " | ./main > test.out";
        system(cmd.c_str());
        ifstream result("test.out");
        int score;
        result >> score;
        (*stats)[name][test_name] = score;
    }
}


void rebuild_report(statistics* stats, string baseline_name){
    ofstream file;
    if(baseline_name.size()>0){
        file.open("scoring/"+baseline_name+".md");
        file << "# Scoring against " << baseline_name << endl << endl; 
    } else{
        file.open("README.md");
        file << "# Global scores " << baseline_name << endl << endl;
    }
    file << "| "; 
    for(auto& test : tests)
    {
        file << "| " << test << " ";
    }
    file << "|" << endl;
    
    file << "| --- ";
    for(auto& test : tests)
    {
        file << "| --- ";
    }
    file << "|" << endl;
    
    for(auto& run : *stats)
    {
        file << "| " << run.first;
        for(auto& test : run.second){
            double value = test.second;
            if(baseline_name.size()>0){
                value = 100*value/(*stats)[baseline_name][test.first];
                file << "|  " << value << "% ";
            }
            else{
                file << "|  " << value << " ";
            }
            
            
        }
        file << "|" << endl;
    }
    

    
}

int main(int argc, char* argv[]) {
    

    statistics stats = load_statistics();

    if(argc<2){
        return 1;
    }
    
    string run_name = argv[1];
    if(run_name!="skip"){
        system("make build");
        score(&stats, run_name);    
    }
    
    rebuild_report(&stats, "");
    
    for(size_t i = 2; i < argc; i++)
    {
        rebuild_report(&stats, argv[i]);
    }
    
    
    dump_statistics(stats);
    system("git add .");
    
    system(("git commit -m \"" + run_name + " scored\" ").c_str());
	
    
    system("git push");
    return 0;
}