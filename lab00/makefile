CC=gcc
CFLAGS=-c -Wall

all: hello

run: hello
	./hello

hello: main.o factorial.o hello.o
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $^

clean:
	rm *.o hello
