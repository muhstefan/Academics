CC=gcc
CFLAGS=-Wall -Wextra -Werror
BUILD=../build/



all: cipher

cipher: cipher.o
	$(CC) $(CFLAGS) cipher.o -o $(BUILD)cipher

cipher.o: cipher.c
	$(CC) $(CFLAGS) -c cipher.c -o cipher.o

clean:
	rm -rf *.o $(BUILD)Quest_*
