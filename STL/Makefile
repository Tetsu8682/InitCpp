all:personne.o figure.o prog

personne.o: personne.cpp
	g++ -c -g -Wall -Wextra -Werror personne.cpp -o personne.o

figure.o: figure.cpp
	g++ -c -g -Wall -Wextra -Werror figure.cpp -o figure.o

prog: personne.o figure.o main.cpp
	g++ personne.o figure.o main.cpp -g -Wall -Wextra -Werror -o prog