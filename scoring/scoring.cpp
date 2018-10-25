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

using Clock = chrono::steady_clock;
using Microseconds = chrono::microseconds;
using Time = Clock::time_point;
vector<string> tests; //= {"fair_salesman_small.in", 
                        // "not_regular_only_small.in",  "one_cicle_small.in",  
                        // "public3.in",  "regular_small.in" , "whirl_small.in"};

string test_folder = "tests";

void read_directory(const std::string& name)
{
    system("ls tests > scoring/tests.txt");
    ifstream f("scoring/tests.txt");
    while(!f.eof()){
        string test;
        f >> test;
        if(test.size()>=2){
            tests.push_back(test);
            cerr << test << endl; 
        }
    }
    
}

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
    // if(stats->find(name)!=stats->end()){
    //     cerr << name << " exists" << endl;
    //     exit(1);
    // }
    
    for(auto& test_name : tests){
        string cmd = "cat " + test_folder + "/" + test_name + " | ./" + name + ".bin > test.out";
        if(system(cmd.c_str())!=0){
            cerr << "your solution failed. Your scores so far:" << endl;
             for(auto& test : (*stats)[name]){
                cerr << test.first << " " << test.second << endl;
             }
            exit(228);

        }

        ifstream result("test.out");
        int score;
        result >> score;
        if((*stats)[name][test_name]>0 and (*stats)[name][test_name]!=score){
            cerr << "Solution " << name << " printed somewhat different on " << test_name << ". Old score "<<(*stats)[name][test_name] <<
             " new score " << score << ". Cannot proceed. Sorry" << endl;
             exit(1);
        }
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
        for(string& test_name : tests){
            double value = run.second[test_name];
            if(baseline_name.size()>0){
                value = 100*(*stats)[baseline_name][test_name]/value;
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
    
    read_directory("tests");
    statistics stats = load_statistics();

    if(argc<2){
        return 1;
    }
    
    string run_name = argv[1];
    if(run_name!="skip"){
        string cmd = "./build.sh solutions/" + run_name + ".cpp " + run_name + ".bin";

        if(system(cmd.c_str())!=0){
            cerr << "Failed to build. Sorry" << endl;
            exit(228);
        }
        score(&stats, run_name);    
    }
    
    rebuild_report(&stats, "");
    
    for(size_t i = 2; i < argc; i++)
    {
        string baseline_name = argv[i];
        cerr << stats.size() << endl;
        if(stats.find(baseline_name) == stats.end()){
            cerr << "Cant find " << baseline_name << " solution. Sorry" << endl;
            exit(2);
        }
        rebuild_report(&stats, baseline_name);
    }
    
    
    dump_statistics(stats);
    // system("git add .");
    
    // system(("git commit -m \"" + run_name + " scored\" ").c_str());
	

    // system("git push");
    return 0;
}