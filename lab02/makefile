CC=gcc
LDFLAGS=-lpthread
CFLAGS=-Wall -std=gnu99

all:pthreads_example00a pthreads_example00b \
	pthreads_example01a pthreads_example01b \
	pthreads_example02a pthreads_example02b \
	pthreads_example03a pthreads_example03b pthreads_example03c pthreads_example03d\
	pthreads_example04a pthreads_example04b \
	pthreads_example05a pthreads_example05b \
	pthreads_example06a

%:%.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f pthreads_example00a pthreads_example00b \
	pthreads_example01a pthreads_example01b \
	pthreads_example02a pthreads_example02b \
	pthreads_example03a pthreads_example03b pthreads_example03c pthreads_example03d\
	pthreads_example04a pthreads_example04b \
	pthreads_example05a pthreads_example05b	\
	pthreads_example06a
