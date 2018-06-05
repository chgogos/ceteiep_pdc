CC=gcc
LDFLAGS=-fopenmp -lm
CFLAGS=-Wall

all:openmp_exercise01 \
	openmp_exercise02 \
	openmp_exercise03 \
	openmp_exercise04 \
	openmp_exercise05 \
	openmp_exercise06 

%:%.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f openmp_exercise01 \
	openmp_exercise02 \
	openmp_exercise03 \
	openmp_exercise04 \
	openmp_exercise05 \
	openmp_exercise06 
