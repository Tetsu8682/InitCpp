all: ensemble.o prog

ensemble.o: ensemble.cpp
	g++ -c -g -Wextra -Wall -Werror ensemble.cpp -o ensemble.o

prog:main.cpp ensemble.o
	g++ main.cpp ensemble.o -Wall -Wextra -Werror -g -o prog 