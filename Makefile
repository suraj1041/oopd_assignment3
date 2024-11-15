test:
	g++ -c main.cpp
	g++ -g -o debug main.o
	g++ -O3 -o optimize main.o