#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

int main(int argc, char* argv[]){
	int my_rank, comm_sz; 
	int a=0, sum;

	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    if (my_rank!=0){
        srand(time(NULL)*my_rank);
        a = rand() % 100 + 1;
        printf("Process %d produced value %d\n", my_rank, a);
    }
	// MPI_Reduce(&a, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Allreduce(&a, &sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
	if (my_rank==0)
		printf("The sum is %d (for process 0)\n", sum);
    else
        printf("The value of sum that process %d knows is %d\n", my_rank, sum);

	MPI_Finalize();
	return 0;
}

/*
$ mpicc mpi_example05.c
$ mpiexec -n 4 ./a.out
Process 1 produced value 4
Process 3 produced value 58
Process 2 produced value 23
The sum is 85 (for process 0)
The value of sum that process 1 knows is 85
The value of sum that process 2 knows is 85
The value of sum that process 3 knows is 85
*/