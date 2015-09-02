CC=g++
CPPFLAGS=-Wall -Wextra -pedantic -ggdb -c -std=c++11
DEP=vector.o matriz.o

all: altohorno

altohorno: altohorno.o $(DEP)
	$(CC) altohorno.o $(DEP) -o altohorno

main: main.o 
	$(CC) main.o -o main

%.o: %.cpp
	$(CC) $(CPPFLAGS) $< -o $@

clean:
	rm -f *.o
	rm -f main altohorno
