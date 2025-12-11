all:rectangle.o prog 

rectangle.o: rectangle.cpp
	g++ -c -g -Wextra -Wall -Werror rectangle.cpp -o rectangle.o

prog: main.cpp ../s3/figure.o rectangle.o
	g++ main.cpp ../s3/figure.o rectangle.o -Wall -Wextra -Werror -g -o prog 