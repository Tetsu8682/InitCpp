all: string.o main.o compte.o prog

string.o: string.cpp string.hpp
	g++ -c -Wall -Wextra -Werror -g string.cpp

compte.o: compte.cpp compte.hpp
	g++ -c -Wall -Wextra -Werror -g -O0 -g3 compte.cpp

main.o: main.cpp
	g++ -c -Wall -Wextra -Werror -g main.cpp

prog: main.o
	g++ -g main.o string.o compte.o -o prog
