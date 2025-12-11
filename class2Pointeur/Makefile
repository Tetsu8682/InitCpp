all: figure.o main.o prog

figure.o: figure.cpp
	g++ -c -Wall -Wextra -Werror -g figure.cpp

main.o: main.cpp
	g++ -c -Wall -Wextra -Werror -g main.cpp

prog: figure.o main.o
	g++ main.o figure.o -Wall -Wextra -Werror -g -o prog 