# Build
build:
	./build.sh main.cpp main

build-scoring:
	g++ -O2 scoring/scoring.cpp --std=c++17 -o score

debug:
	g++ -std=c++14 -DDEBUG -pthread -O0 main.cpp -o main -Wall -Wextra -Winline -Wshadow -g -Wno-inline

# Run
run: build
	cat sample.in | ./main
	cat public/1.in | ./main

runall: build
	mkdir -p out
	cat public/1.in | ./main > out/1.out
	cat public/2.in | ./main > out/2.out
	cat public/3.in | ./main > out/3.out
	cat public/4.in | ./main > out/4.out

runtests: build
	cat tests/public3.in | ./main > out/public3.out
	cat tests/whirl_small.in | ./main > out/whirl_small.out
	cat tests/one_cicle_small.in | ./main > out/one_cicle_small.out
	cat tests/regular_small.in | ./main > out/regular_small.out
	cat tests/not_regular_only_small.in | ./main > out/not_regular_only_small.out
	cat tests/fair_salesman_small.in | ./main > out/fair_salesman_small.out

score: build-scoring
	./score simple
	./score skip simple

generate:
	g++ -std=c++14 -O0 generation.cpp -o gen
	./gen

# Other
download:
	mkdir -p public
	wget https://problems.sphere-engine.com/problems/TSALESMAN2/resources/get/1.in -O public/1.in
	wget https://problems.sphere-engine.com/problems/TSALESMAN2/resources/get/2.in -O public/2.in
	wget https://problems.sphere-engine.com/problems/TSALESMAN2/resources/get/3.in -O public/3.in
	wget https://problems.sphere-engine.com/problems/TSALESMAN2/resources/get/4.in -O public/4.in

submit:
	cat basic_structs.cpp run.cpp dp.cpp local_search.cpp greedy.cpp newmain.cpp main.cpp | grep -v nosubmit > submit.cpp
	cat submit.cpp | xsel -b

profile:
	g++ -pg main.cpp -O2 -std=c++14 -DDEBUG  -o main  # -fsanitize=undefined  -fsanitize=leak -fsanitize=null -pthread -Wall -Wextra  -Wshadow
	cat public/3.in |./main
	gprof ./main > profile