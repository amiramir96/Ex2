CC = gcc
AR = ar
FLAGS = -Wall -g

#compile all
all: connections  

#connection process
connections: main.o 
	$(CC) $(FLAGS) -o connections main.o my_mat.c

#compile main
main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c 

#clean process
.PHONY: clean all


clean:
	rm -f *.o *.a *.so connections