CC=mpicc
LDFLAGS=-lm
CFLAGS=-Wall

all:mpi_exercise01 \
	mpi_exercise02 \
	mpi_exercise03a mpi_exercise03b mpi_exercise03c \
	mpi_exercise04 
	

%:%.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f mpi_exercise01 \
	mpi_exercise02 \
	mpi_exercise03a mpi_exercise03b mpi_exercise03c \
	mpi_exercise04 \
