CC=gcc
# gnu99 C99 + extensions provided by gcc by default
CFLAGS=-c -Wall -std=gnu99

all: hello

run: hello
	./hello

hello: main.o factorial.o hello.o
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $^

.PHONY:clean
clean:
	rm *.o hello
