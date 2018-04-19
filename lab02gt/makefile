CC=gcc
CFLAGS=-Wall -std=gnu99
LDFLAGS=-lpthread

all: example01

example01:example01.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)


.PHONY:clean
clean:
	rm -f example01
