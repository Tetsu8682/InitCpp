all: ensemble.o exception.o rationnel.o prog

ensemble.o: ensemble.cpp
	g++ -c -g -Wextra -Wall -Werror ensemble.cpp -o ensemble.o

exception.o: exception.cpp
	g++ -c -g -Wextra -Wall -Werror exception.cpp -o exception.o

rationnel.o: rationnel.cpp
	g++ -c -g -Wextra -Wall -Werror rationnel.cpp -o rationnel.o

prog: ensemble.o exception.o main.cpp
	g++ ensemble.o exception.o rationnel.o main.cpp -g -Wextra -Wall -Werror -o prog
