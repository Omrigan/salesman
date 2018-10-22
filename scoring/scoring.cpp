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

using namespace std;

// TODO: unify variables namestyle
// TODO: use better random

using Clock = chrono::steady_clock;
using Microseconds = chrono::microseconds;
using Time = Clock::time_point;
vector<string> tests = {"1.in"};
string test_folder = "public";

void make_baseline(string name){
    ofstream base("scoring/basline-" + name + ".txt");
    
    
    for(int i = 0; i < tests.size(); ++i){
        string cmd = "cat " + test_folder + "/" + tests[i] + " | ./main > test.out";
        system(cmd.c_str());
        ifstream result("test.out");
        int score;
        result >> score;
        base << tests[i] << " " << score; 


    }
    
}

void score(string name, string baseline){
    ifstream base("scoring/basline-" + name + ".txt");
    ofstream report("README.md", ios_base::app);
    report << "|" << name << "|" << baseline << "|"; 
    cerr << "Scoring " << name << ". Baseline: " << baseline;
    
    while(!base.eof()){
        string test_name;
        int base_score;
        base >> test_name >> base_score;
        string cmd = "cat " + test_folder + "/" + test_name + " | ./main > test.out";
        system(cmd.c_str());
        ifstream result("test.out");
        int score;
        result >> score;
        double percent = (100. * score)/base_score;
        cerr << test_name << " Relative score: " << percent << " Baseline score: " <<  base_score << " Current score: "  << score << endl;
        report << test_name << ":" << percent << "|";
    }
}

int main(int argc, char* argv[]) {
    if(argc < 3){
        return 1;
    }
    string first = argv[1], second = argv[2];

    if(first=="make-baseline"){
        cerr << "Make baseline" << endl;
        make_baseline(second);

    }
    else{
        score(first, second);
    }
    
	return 0;
}