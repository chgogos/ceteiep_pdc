#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 10

int main(){
    int a[N], *local_a;
    int my_rank, comm_sz, local_n;
    MPI_Init(NULL,NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    for(int i=0;i<10;i++){
        a[i]=i;
    }
    local_n= N/comm_sz;
    local_a=malloc(sizeof(int)*local_n);
    MPI_Scatter(a,local_n, MPI_INT, local_a, local_n, MPI_INT, 0, MPI_COMM_WORLD);
    for (int i=0;i<local_n;i++)
        printf("MPI Process %d has value %d\n", my_rank, local_a[i]);
    MPI_Finalize();
}

