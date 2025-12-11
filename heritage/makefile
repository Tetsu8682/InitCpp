all: vehicule.o main.o prog

vehicule.o: vehicule.cpp vehicule.hpp
	g++ -c -g -Wall -Wextra -Werror vehicule.cpp -o vehicule.o

main.o: main.cpp
	g++ -c -g -Wall -Wextra -Werror main.cpp -o main.o
	
prog: main.o vehicule.o
	g++ -g -Wextra -Werror -Wall main.o vehicule.o -o prog
