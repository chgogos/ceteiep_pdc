CC=gcc
CFLAGS=-Wall -pthread

all: pthreads_exercise01 pthreads_exercise02 pthreads_exercise03 \
	pthreads_exercise04a pthreads_exercise04b pthreads_exercise05 pthreads_exercise06

pthreads_exercise04a:pthreads_exercise04a.c
	$(CC) $(CFLAGS) $^ -o $@ -lm

pthreads_exercise04b:pthreads_exercise04b.c
	$(CC) $(CFLAGS) $^ -o $@ -lm -lgsl -lgslcblas

%:%.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f pthreads_exercise01 pthreads_exercise02 pthreads_exercise03 \
	pthreads_exercise04a pthreads_exercise04b pthreads_exercise05 pthreads_exercise06
