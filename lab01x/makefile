CC=gcc
CFLAGS=-Wall

all: fork_exercise01 fork_exercise02 fork_exercise03 fork_exercise04 fork_exercise05 fork_exercise06a fork_exercise06b fork_exercise07a fork_exercise07b 

fork_exercise07a:fork_exercise07a.c
	$(CC) $(CFLAGS) $^ -o $@ -lm

fork_exercise07b:fork_exercise07b.c
	$(CC) $(CFLAGS) $^ -o $@ -lm

%:%.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f fork_exercise01 fork_exercise02 fork_exercise03 fork_exercise04 fork_exercise05 fork_exercise06a fork_exercise06b fork_exercise07a fork_exercise07b
