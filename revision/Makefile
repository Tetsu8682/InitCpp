all: date.o prog

date.o: date.cpp
	g++ -c -Wall -Wextra date.cpp

prog: main.cpp date.o 
	g++ main.cpp date.o -Wall -Wextra -g -o prog