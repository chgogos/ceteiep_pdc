CC=gcc
CFLAGS=-c -Wall

all: hello

run: hello
	./hello

hello: main.o factorial.o hello.o
	$(CC) main.o factorial.o hello.o -o hello

main.o: main.c
	$(CC) $(CFLAGS) main.c

factorial.o: factorial.c
	$(CC) $(CFLAGS) factorial.c

hello.o: hello.c
	$(CC) $(CFLAGS) hello.c

clean:
	rm *.o hello
