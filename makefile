CC = gcc
AR = ar
FLAGS = -Wall -g


all: connections  


connections: main.o 
	$(CC) $(FLAGS) -o connections main.o my_mat.c


main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c 


.PHONY: clean all


clean:
	rm -f *.o *.a *.so connections
