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
	g++ -DDEBUG -O2 main.cpp -o main

debug: 
	g++ -O0 main.cpp -o main
	cat public/2.in | gdb ./main > out/2.out

download:
	mkdir -p public
	wget https://problems.sphere-engine.com/problems/TSALESMAN2/resources/get/1.in -O public/1.in
	wget https://problems.sphere-engine.com/problems/TSALESMAN2/resources/get/2.in -O public/2.in
	wget https://problems.sphere-engine.com/problems/TSALESMAN2/resources/get/3.in -O public/3.in
	wget https://problems.sphere-engine.com/problems/TSALESMAN2/resources/get/4.in -O public/4.in