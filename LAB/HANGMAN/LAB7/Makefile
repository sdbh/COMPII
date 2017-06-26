CC = gcc
CFLAGS = -Wall --std=c99 -g
OBJECTS = main.o my_string.o generic_vector.o bst.o

string_driver: $(OBJECTS)
	$(CC) $(CFLAGS) -o string_driver $(OBJECTS)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
my_string.o: my_string.c
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o
generic_vector.o: generic_vector.c
	$(CC) $(CFLAGS) -c generic_vector.c -o generic_vector.o
bst.o: bst.c
	$(CC) $(CFLAGS) -c bst.c -o bst.o
clean:
	rm $(OBJECTS)
