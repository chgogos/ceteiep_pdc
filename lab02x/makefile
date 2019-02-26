CC=gcc
CFLAGS=-Wall -std=gnu99
LDFLAGS=-lpthread

all: pthreads_exercise01 pthreads_exercise02a pthreads_exercise02b \
	pthreads_exercise03 pthreads_exercise04a pthreads_exercise05 pthreads_exercise06

pthreads_exercise01:pthreads_exercise01.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

pthreads_exercise02a:pthreads_exercise02a.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

pthreads_exercise02b:pthreads_exercise02b.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

pthreads_exercise03:pthreads_exercise03.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

pthreads_exercise04a:pthreads_exercise04a.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) -lm

pthreads_exercise05:pthreads_exercise05.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

pthreads_exercise06:pthreads_exercise06.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

.PHONY:clean
clean:
	rm -f pthreads_exercise01 pthreads_exercise02 pthreads_exercise03 \
	pthreads_exercise04a pthreads_exercise05 pthreads_exercise06
