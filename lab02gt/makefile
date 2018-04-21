CC=gcc
CFLAGS=-Wall -std=gnu99
LDFLAGS=-lpthread

all: example01a example01b \
	example02 \
	example03

%:%.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

.PHONY:clean
clean:
	rm -f example01a example01b \
		example02 \
		example03