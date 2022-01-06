CC=gcc
AR=ar
OBJECT_MAIN=main.o
OBJECT_LIB=NumClass.o
FLAGS=-Wall -g

all: mat graph

graph:main.o libclassnode.a
	$(CC) $(FLAGS) -o graph main.o libclassnode.a


mat: libclassnode.a


libclassnode.a: graph.o Node.o Edge.o algo.o
	$(AR) -rcs -o libclassnode.a graph.o Node.o Edge.o algo.o


graph.o : graph.c graph.h
	$(CC) $(FLAGS) -c graph.c

Node.o : Node.c graph.h
	$(CC) $(FLAGS) -c Node.c

Edge.o : Edge.c graph.h
	$(CC) $(FLAGS) -c Edge.c

algo.o : algo.c graph.h
	$(CC) $(FLAGS) -c algo.c


main.o: main.c graph.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
		rm -f *.o *.a graph