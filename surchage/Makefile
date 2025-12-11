all: rationnel.o main.o prog

rationnel.o: rationnel.cpp rationnel.hpp
	g++ -c -Wall -Wextra -Werror -g rationnel.cpp

main.o: main.cpp
	g++ -c -Wall -Wextra -Werror -g main.cpp

prog:main.o rationnel.o
	g++ -g -Werror -Wextra -Wall main.o rationnel.o -o prog