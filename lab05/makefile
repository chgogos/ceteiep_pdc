CC=mpicc
LDFLAGS=
CFLAGS=-Wall

all:mpi_example01 \
	mpi_example02 \
	mpi_example03 \
	mpi_example04 \
	mpi_example05 \
	mpi_example06 \
	mpi_example07 \
	mpi_example08 

%:%.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f mpi_example01 \
	mpi_example02 \
	mpi_example03 \
	mpi_example04 \
	mpi_example05 \
	mpi_example06 \
	mpi_example07 \
	mpi_example08 \
