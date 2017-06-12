CC = gcc
CFLAGS = -Wall --std=c99 -g
OBJECTS = main.o my_string.o unit_test.o test_def.o

unit_test: unit_test.o test_def.o my_string.o
	$(CC) $(CFLAGS) -o unit_test unit_test.o test_def.o my_string.o
unit_test.o: unit_test.c
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o
test_def.o: test_def.c
	$(CC) $(CFLAGS) -c test_def.c -o test_def.o
string_driver: $(OBJECTS)
	$(CC) $(CFLAGS) -o string_driver $(OBJECTS)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
my_string.o: my_string.c
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o
clean:
	rm $(OBJECTS)
