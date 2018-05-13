CC=gcc
LDFLAGS=-fopenmp -lm 
CFLAGS=-Wall

all:openmp_example01a openmp_example01b openmp_example01c\
	openmp_example02a openmp_example02b \
	openmp_example03a openmp_example03b openmp_example03c \
	openmp_example04a \
	openmp_example05a openmp_example05b \
	openmp_example06 \
	openmp_example07 \
	openmp_example08

%:%.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f openmp_example01a openmp_example01b openmp_example01c \
	openmp_example02a openmp_example02b \
	openmp_example03a openmp_example03b openmp_example03c \
	openmp_example04a \
	openmp_example05a openmp_example05b \
	openmp_example06 \
	openmp_example07 \
	openmp_example08
