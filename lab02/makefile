CC=gcc
CFLAGS=-Wall
LDFLAGS=-lpthread

all: pthreads_example01a pthreads_example01b pthreads_example02a pthreads_example02b \
	pthreads_example03a pthreads_example03b pthreads_example03c pthreads_example04a pthreads_example04b \
	pthreads_example05a pthreads_example05b

%:%.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f pthreads_example01a pthreads_example01b pthreads_example02a pthreads_example02b \
	pthreads_example03a pthreads_example03b pthreads_example03c pthreads_example04a pthreads_example04b \
	pthreads_example05a pthreads_example05b	
