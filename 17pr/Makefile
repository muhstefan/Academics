CC=gcc
CFLAGS=-Wall -Wextra -Werror
BUILD=../build/



all: door_struct list_test stack_test

door_struct: dmanager_init.o
	$(CC) $(CFLAGS) dmanager_init.o -o $(BUILD)Quest_1

dmanager_init.o: dmanager_module.c
	$(CC) $(CFLAGS) -DDOORS -c dmanager_module.c -o dmanager_init.o

list_test: dmanager_tests.o list_test.o list.o
	$(CC) $(CFLAGS) dmanager_tests.o list_test.o list.o -o $(BUILD)Quest_2

dmanager_tests.o: dmanager_module.c
	$(CC) $(CFLAGS) -DTESTS -c dmanager_module.c -o dmanager_tests.o

list_test.o: list_test.c
	$(CC) $(CFLAGS) -c list_test.c -o list_test.o

list.o: list.c
	$(CC) $(CFLAGS) -c list.c -o list.o

stack_test: stack_test.o stack.o
	$(CC) $(CFLAGS) stack_test.o stack.o -o $(BUILD)Quest_3

stack_test.o: stack_test.c
	$(CC) $(CFLAGS) -c stack_test.c -o stack_test.o

stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c -o stack.o

clean:
	rm -rf *.o $(BUILD)Quest_*



