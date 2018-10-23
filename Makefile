run: build
	cat sample.in | ./main
	cat public/1.in | ./main

runall: build
	mkdir -p out
	cat public/1.in | ./main > out/1.out
	cat public/2.in | ./main > out/2.out
	cat public/3.in | ./main > out/3.out
	cat public/4.in | ./main > out/4.out

build:
	g++ -std=c++14 -DDEBUG -pthread -O2 main.cpp -o main

build-scoring:
	g++ -O2 scoring/scoring.cpp -o score

debug:
	g++ -O0 main.cpp -o main -g -fsanitize=leak -fsanitize=null -pthread

download:
	mkdir -p public
	wget https://problems.sphere-engine.com/problems/TSALESMAN2/resources/get/1.in -O public/1.in
	wget https://problems.sphere-engine.com/problems/TSALESMAN2/resources/get/2.in -O public/2.in
	wget https://problems.sphere-engine.com/problems/TSALESMAN2/resources/get/3.in -O public/3.in
	wget https://problems.sphere-engine.com/problems/TSALESMAN2/resources/get/4.in -O public/4.in

submit:
	cat basic_structs.cpp run.cpp local_search.cpp dp.cpp greedy.cpp main.cpp | grep -v nosubmit > submit.cpp
	cat submit.cpp | xsel -b

baseline: build-scoring
	./score make-baseline current

generate:
	g++ -std=c++14 -O0 generation.cpp -o gen
	./gen

runtests: build
	cat tests/whirl_small.in | ./main > out/whirl_small.out
	cat tests/one_cicle_small.in | ./main > out/one_cicle_small.out
	cat tests/regular_small.in | ./main > out/regular_small.out
	cat tests/not_regular_only_small.in | ./main > out/not_regular_only_small.out
	cat tests/fair_salesman_small.in | ./main > out/fair_salesman_small.out
