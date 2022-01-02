CC=gcc
AR=ar
OBJECT_MAIN=main.o
OBJECT_LIB=NumClass.o
FLAGS=-Wall -g   

all: mat connections 
 
connections:main.o libclassnode.a
	$(CC) $(FLAGS) -o connections main.o libclassnode.a


mat: libclassnode.a	



libclassnode.a: nodes.o   
	$(AR) -rcs -o libclassnode.a nodes.o 



nodes.o : nodes.c nodes.h
	$(CC) $(FLAGS) -c nodes.c 	



main.o: main.c nodes.h
	$(CC) $(FLAGS) -c main.c   
	
.PHONY: clean all

clean:
		rm -f *.o *.a connections   