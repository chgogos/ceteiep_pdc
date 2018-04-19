CC=gcc
CFLAGS=-Wall -std=gnu99
LDFLAGS=-lpthread

all: example01a example01b \
	example02 \
	example03

example01a:example01a.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

example01b:example01b.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

example02:example02.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

example03:example03.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

.PHONY:clean
clean:
	rm -f example01a example01b example02 example03