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
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cmath>

#include "basic_structs.cpp"

using namespace std;

namespace gen {
    int random(int a, int b) {
        if (b <= a)
            cerr << "INVALID ARGUMENT\n";
        return RandomGenerator::gen_rand_int() % (b - a) + a;
    }

    struct AirportName {
        string name = "AAA";
        string next() {
            for (int i = 2; i != -1; i--) {
                if (name[i] != 'Z') {
                    name[i]++;
                    break;
                }
                name[i] = 'A';
                if (i == 0)
                    return "-";
            }
            return name;
        }
        vector<string> get_list() {
            vector<string> ret;
            string cur = this->next();
            while (cur != "-") {
                ret.push_back(cur);
                cur = next();
            }
            return ret;
        }
    };

    struct RegionName {
        string name = "AAAAA";

        string next() {
            for (int i = 4; i != -1; i--) {
                if (name[i] != 'Z') {
                    name[i]++;
                    break;
                }
                name[i] = 'A';
                if (i == 0)
                    return "-";
            }
            return name;
        }

        vector<string> get_list() {
            vector<string> ret;
            string cur = this->next();
            while (cur != "-") {
                ret.push_back(cur);
                cur = next();
            }
            return ret;
        }
    };

    struct Params {
        int N = 300; // number of areas;
        int NA = 300; // number of airports;
        string sz_type; // small - 0; medium - 1; large - 2;
        int max_cost = 10000;
        int min_cost = 0;
        int min_time = 0;
        int max_time = 300;
        int prob = 30; // probability of edge
        int MAX_PROB = 100;
        string path = "./tests/";
        struct AirportName an;
        struct RegionName rn;
        vector<string> specific;
        void init() {
            if (sz_type == "small") {
                N = random(3, 11);
                NA = random(N, 50);
            } else if (sz_type == "medium") {
                N = random(11, 101);
                NA = random(N, 200);
            } else if (sz_type == "large") {
                N = random(101, 300);
                N = random(N, 301);
            }
            max_time = N;
            for (string & specific_s : specific) {
                if (specific_s == "regular")
                    max_time = 0;
                if (specific_s == "not_regular_only") {
                    min_time = 1;
                }
                if (specific_s == "fair_salesman") {
                    NA = N;
                }
            }
        }
        bool is_edge() {
            return RandomGenerator::get_rand_int() % MAX_PROB < prob;
        }
    };

    struct Edge;

    struct Airport {
        int idx, zone;
    };
    struct Edge {
        Airport *from;
        Airport *to;
        int day, cost;
    };


    void save_test(string name, Params * param, vector<Airport> * airports, vector<Edge> & edges, vector<vector<Airport *> > & abr) {
        vector<string> airp_names = param->an.get_list();
        vector<string> region_names = param->rn.get_list();
        //  FILE * ff = freopen(name.c_str(), "w", stdout);
        cout << "saving test in " << name << '\n';
        std::ofstream out(name);
        std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
        std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

        cout << param->N << ' ' << airp_names[0] << '\n';
        for (int i = 0; i < param->N; i++) {
            cout << region_names[i] << '\n';
            for (int j = 0; j < abr[i].size(); j++) {
                cout << airp_names[abr[i][j]->idx] << ' ';
            }
            cout << '\n';
        }
        for (Edge & edge: edges) {
            cout << airp_names[edge.from->idx] << ' ' << airp_names[edge.to->idx] << ' ' << edge.day << ' ' << edge.cost << '\n';
        }
        std::cout.rdbuf(coutbuf); //reset to standard output again

    }
    void save_test_eucledean(string name, Params * param, vector<Airport> * airports, vector<Edge> & edges, vector<vector<pair<Airport *, pair<long long, long long> > > > & abr) {
        vector<vector<Airport *> > abr_(abr.size());
        for (int i = 0; i < abr.size(); i++) {
            for (int j = 0; j < abr[i].size(); j++) {
                abr_[i].push_back(abr[i][j].first);
            }
        }
        save_test(name, param, airports, edges, abr_);
    }
    string join(vector<string> inp) {
        string s = "";
        for (string & sub : inp) {
            s += sub + '_';
        }
        return s;
    }
    void gen_simple(Params * param) {
        //
        // можно варьировать вероятность ребра prob
        //
        string name = param->path + join(param->specific) + param->sz_type + ".in";
        std::vector<Airport> airports;
        airports.reserve(param->NA + 10);
        std::vector<Edge> edges;
        vector<vector<Airport *> > air_by_region(param->N);

        for (int idx = 0; idx < param->NA; idx++) {
            int zone;
            if (idx < param->N) {
                zone = idx;
            } else {
                zone = random(0, param->N);
            }
            // cout << zone << '\n';
            airports.push_back({idx, zone});
            // cout << "idx " << airports[idx].idx << '\n';
            air_by_region[zone].push_back(&(airports[idx]));
        }
        // maybe random shuffle
        for (int time = param->min_time; time <= param->max_time; time++) {
            for (int i = 0; i < param->N; i++) {
                for (int j = 0; j < param->N; j++) {
                    if (j == i)
                        continue;
                    for (int a1 = 0; a1 < air_by_region[i].size(); a1++) {
                        for (int a2 = 0; a2 < air_by_region[j].size(); a2++) {
                            if (param->is_edge()) {
                                edges.push_back({air_by_region[i][a1], air_by_region[j][a2], time,
                                                 random(param->min_cost, param->max_cost)});
                            }
                        }
                    }
                }
            }
        }
        save_test(name, param, &airports, edges, air_by_region);
    }
    void gen_cicle(Params * param) {
        //
        // граф с одним циклом (возможно интереснее добавить шумовых ребер)
        //
        string name = param->path + join(param->specific) + param->sz_type + ".in";
        std::vector<Airport> airports;
        airports.reserve(param->NA + 10);
        std::vector<Edge> edges;
        vector<vector<Airport *> > air_by_region(param->N);

        for (int idx = 0; idx < param->NA; idx++) {
            int zone;
            if (idx < param->N) {
                zone = idx;
            } else {
                zone = random(0, param->N);
            }
            // cout << zone << '\n';
            airports.push_back({idx, zone});
            // cout << "idx " << airports[idx].idx << '\n';
            air_by_region[zone].push_back(&(airports[idx]));
        }
        // maybe random shuffle
        for (int i = 1; i < param->N; i++) {
            edges.push_back({air_by_region[i-1][0], air_by_region[i][0], i,
                             random(param->min_cost, param->max_cost)});

        }
        edges.push_back({air_by_region[param->N - 1][0], air_by_region[0][0], param->N,
                         random(param->min_cost, param->max_cost)});
        save_test(name, param, &airports, edges, air_by_region);
    }
    void gen_whirl(Params * param) {
        //
        // граф колесо
        //
        string name = param->path + join(param->specific) + param->sz_type + ".in";
        std::vector<Airport> airports;
        airports.reserve(param->NA + 10);
        std::vector<Edge> edges;
        vector<vector<Airport *> > air_by_region(param->N);

        for (int idx = 0; idx < param->NA; idx++) {
            int zone;
            if (idx < param->N) {
                zone = idx;
            } else {
                zone = random(0, param->N);
            }
            // cout << zone << '\n';
            airports.push_back({idx, zone});
            // cout << "idx " << airports[idx].idx << '\n';
            air_by_region[zone].push_back(&(airports[idx]));
        }
        // maybe random shuffle

        for (int i = 2; i < param->N; i++) {
            //  ребро от центра в нуле
            edges.push_back({air_by_region[0][0], air_by_region[i][0], 0,
                             random(param->min_cost, param->max_cost)});
            edges.push_back({air_by_region[i-1][0], air_by_region[i][0], 0,
                             random(param->min_cost, param->max_cost)});
        }
        edges.push_back({air_by_region[param->N - 1][0], air_by_region[1][0], 0,
                         random(param->min_cost, param->max_cost)});

        //  добавим обратные ребра
        size_t sz = edges.size();
        for (int e = 0; e < sz; e++) {
            edges.push_back({edges[e].to, edges[e].from, 0, random(param->min_cost, param->max_cost)});
        }
        save_test(name, param, &airports, edges, air_by_region);
    }

    long long dist(pair<long long, long long> & a, pair<long long, long long> & b) {
        return (long long)std::sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
    }
    void gen_eucledian(Params * param) {
        //
        // граф с неравенством треугольника
        //
        string name = param->path + join(param->specific) + param->sz_type + ".in";
        std::vector<Airport> airports;
        airports.reserve(param->NA + 10);
        std::vector<Edge> edges;
        vector<vector<pair<Airport *, pair<long long, long long> > > > air_by_region(param->N);
        const int MINP = -1000;
        const int MAXP = 1000;

        for (int idx = 0; idx < param->NA; idx++) {
            int zone;
            if (idx < param->N) {
                zone = idx;
            } else {
                zone = random(0, param->N);
            }
            // cout << zone << '\n';
            airports.push_back({idx, zone});
            // cout << "idx " << airports[idx].idx << '\n';
            air_by_region[zone].push_back({&(airports[idx]), {random(MINP, MAXP), random(MINP, MAXP)}});
        }
        // maybe random shuffle

        for (int time = param->min_time; time <= param->max_time; time++) {
            for (int i = 0; i < param->N; i++) {
                for (int j = 0; j < param->N; j++) {
                    if (j == i)
                        continue;
                    for (int a1 = 0; a1 < air_by_region[i].size(); a1++) {
                        for (int a2 = 0; a2 < air_by_region[j].size(); a2++) {
                            if (param->is_edge()) {
                                edges.push_back({air_by_region[i][a1].first, air_by_region[i][a1].first, time,
                                                 (int)dist(air_by_region[i][a1].second, air_by_region[i][a1].second)});
                            }
                        }
                    }
                }
            }
        }
        save_test_eucledean(name, param, &airports, edges, air_by_region);
    }
}

void simple_generate() {
    // ---------------
    // regular
    {
    gen::Params param_regular { .sz_type = "large", .prob = 40, .specific={"regular"} };
    param_regular.init();
    gen::gen_simple(&param_regular);
    }
    // ---------------
    // not regular
    {
        gen::Params param_without_regular{.sz_type = "large", .prob = 20, .specific={"not_regular_only",  "p20"}};
        param_without_regular.init();
        gen::gen_simple(&param_without_regular);
    }
    {
        gen::Params param_without_regular{.sz_type = "large", .prob = 40, .specific={"not_regular_only",  "p40"}};
        param_without_regular.init();
        gen::gen_simple(&param_without_regular);
    }
    {
        gen::Params param_without_regular{.sz_type = "large", .prob = 80, .specific={"not_regular_only",  "p80"}};
        param_without_regular.init();
        gen::gen_simple(&param_without_regular);
    }
    // ---------------
    // честный коммивояжер
    {
        gen::Params param_fair_salesman{.sz_type = "large", .prob = 50, .specific={"fair_salesman",  "p50"}};
        param_fair_salesman.init();
        gen::gen_simple(&param_fair_salesman);
    }
    {
        gen::Params param_fair_salesman{.sz_type = "large", .prob = 70, .specific={"fair_salesman", "p70"}};
        param_fair_salesman.init();
        gen::gen_simple(&param_fair_salesman);
    }

    {
        gen::Params param_without_regular{.sz_type = "medium", .prob = 20, .specific={"not_regular_only",  "p20"}};
        param_without_regular.init();
        gen::gen_simple(&param_without_regular);
    }
    {
        gen::Params param_without_regular{.sz_type = "medium", .prob = 40, .specific={"not_regular_only",  "p40"}};
        param_without_regular.init();
        gen::gen_simple(&param_without_regular);
    }
    {
        gen::Params param_without_regular{.sz_type = "medium", .prob = 80, .specific={"not_regular_only",  "p80"}};
        param_without_regular.init();
        gen::gen_simple(&param_without_regular);
    }
    // ---------------
    // честный коммивояжер
    {
        gen::Params param_fair_salesman{.sz_type = "medium", .prob = 50, .specific={"fair_salesman",  "p50"}};
        param_fair_salesman.init();
        gen::gen_simple(&param_fair_salesman);
    }
    {
        gen::Params param_fair_salesman{.sz_type = "medium", .prob = 70, .specific={"fair_salesman", "p70"}};
        param_fair_salesman.init();
        gen::gen_simple(&param_fair_salesman);
    }
    // ---------------
    // just один цикл. (возможно интереснее добавить шумовых ребер)
    // gen::Params param_one_cicle { .sz_type = "large", .specific={"one_cicle"} }
    //param_one_cicle.init();
    // gen::gen_cicle(&param_one_cicle);
    // ---------------
    // колесо
    gen::Params param_whirl { .sz_type = "large", .specific={"whirl"} };
    param_whirl.init();
    gen::gen_whirl(&param_whirl);
    // eucledian
    gen::Params param_eucledean { .sz_type = "large", .specific={"eucledian"} };
    param_eucledean.init();
    gen::gen_eucledian(&param_eucledean);
    // eucledian2
    gen::Params param_eucledean1 { .sz_type = "large", .specific={"eucledian", "not_regular_only"} };
    param_eucledean1.init();
    gen::gen_eucledian(&param_eucledean1);
    // eucledian3
    gen::Params param_eucledean3 { .sz_type = "large", .specific={"eucledian", "regular"} };
    param_eucledean3.init();
    gen::gen_eucledian(&param_eucledean3);
    // eucledian3
    gen::Params param_eucledean4 { .sz_type = "large", .specific={"eucledian", "fair_salesman"} };
    param_eucledean4.init();
    gen::gen_eucledian(&param_eucledean4);

}

int main() {
    simple_generate();
}