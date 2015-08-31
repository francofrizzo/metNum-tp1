CC=g++
CPPFLAGS=-Wall -Wextra -pedantic -ggdb -c
DEP=vector.o matriz.o

all: main altohorno

altohorno: altohorno.o $(DEP)
	$(CC) altohorno.o $(DEP) -o altohorno

main: main.o $(DEP)
	$(CC) main.o $(DEP) -o main

%.o: %.cpp
	$(CC) $(CPPFLAGS) $< -o $@

clean:
	rm -f *.o
	rm -f main altohorno
