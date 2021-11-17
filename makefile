CC = gcc
AR = ar
FLAGS = -Wall -g

all: connections  

connections: main.o 
	$(CC) $(FLAGS) -o connections main.o my_mat.c

#static lib, none recursive
# matrixLib: my_matLib.a
# my_matLib.a: my_mat.o
# $(AR) -rcs -o my_matLib.a my_mat.o
#ranlib my_matLib.a

#compilize may_mat.c, static
# my_mat.o: my_mat.c
# $(CC) $(FLAGS) -c my_mat.c 

main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c 

.PHONY: clean all

clean:
	rm -f *.o *.a *.so connections
