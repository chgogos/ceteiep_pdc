// parallel selection sort
// TBC 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define N 100000 // number of elements at the array
#define M 10000000 // the range of random integers values will be [0,M)

void seq_selection_sort(int* a, int n);
void par_selection_sort(int* a, int n);

int main(){
    double start, finish;
    int a[N];
    srand(time(NULL));
    for(int i=0;i<N;i++){
        a[i]=rand() % M;
    }

    start = omp_get_wtime();
    seq_selection_sort(a,N);
    finish = omp_get_wtime();
    printf("Sequential selection sort (%.2f)\n",finish-start);
    int flag=0;
    for(int i=0;i<N-1;i++){
        if (a[i]>a[i+1]){
            flag=1;
            break;
        }
    }
    if (flag==0){
        printf("Sorting OK \n");
    } else{
        printf("Sorting problem \n");
    }
}

void seq_selection_sort(int* a, int n){
    for(int i=0;i<n;i++){
        int pmin = i;
        for(int j=i+1;j<n;j++){
            if (a[j]<a[pmin]){
                pmin=j;
            }
        }
        int temp = a[i];
        a[i]=a[pmin];
        a[pmin]=temp;
    }
}
