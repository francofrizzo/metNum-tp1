CC=g++
CPPFLAGS=-Wall -Wextra -pedantic -ggdb -c
DEP=vector.o matriz.o

all: main altohorno isoterma

altohorno: altohorno.o $(DEP)
	$(CC) altohorno.o $(DEP) -o altohorno

main: main.o $(DEP)
	$(CC) main.o $(DEP) -o main

isoterma: isoterma.o $(DEP)
	$(CC) isoterma.o $(DEP) -o isoterma

%.o: %.cpp
	$(CC) $(CPPFLAGS) $< -o $@

clean:
	rm -f *.o
	rm -f main altohorno
