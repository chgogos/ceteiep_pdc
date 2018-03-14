# makefile για όλα τα παραδείγματα

CC=gcc
CFLAGS=-Wall -std=gnu99

all: fork_example0 fork_example1 fork_example2 fork_example3

fork_example0: fork_example0.c
	$(CC) $(CFLAGS) $^ -o $@

fork_example1: fork_example1.c
	$(CC) $(CFLAGS) $^ -o $@

fork_example2: fork_example2.c
	$(CC) $(CFLAGS) $^ -o $@

fork_example3: fork_example3.c collatz.c
	$(CC) $(CFLAGS) $^ -o $@

.PHONY:clean
clean:
	rm -f fork_example0 fork_example1 fork_example2 fork_example3
