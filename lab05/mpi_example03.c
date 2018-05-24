#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]){
	int my_rank, comm_sz; 
	double a; 
	int b;

	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	if (my_rank==0){
		printf("Enter 2 values (double and int): ");
		scanf("%lf %d",&a,&b);
	}
	MPI_Bcast(&a, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	MPI_Bcast(&b, 1, MPI_INT, 0, MPI_COMM_WORLD); 	
	if (my_rank!=0)
		printf("Process %d got value %lf and value %d\n", my_rank, a, b);

	MPI_Finalize();
	return 0;
}