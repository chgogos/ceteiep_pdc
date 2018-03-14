# θα πρέπει να έχει εγκατασταθεί η βιβλιοθήκη gsl

CC=gcc
CFLAGS=-Wall
LDFLAGS=-lpthread -lm -lgsl -lgslcblas

pthreads_exercise04b:pthreads_exercise04b.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

.PHONY:clean
clean:
	rm -f pthreads_exercise04b
