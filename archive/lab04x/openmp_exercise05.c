// parallel linear search
// comparison with sequential code for 10000 searches over a vector of 1000000 elements

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define N 1000000 // number of elements at the array
#define M 10000000 // the range of random integers values will be [0,M)
#define S 10000 // number of searches

int seq_search(int* a, int n, int key);
int par_search(int* a, int n, int key);

int main(){
    int c;
    double start, finish;
    int a[N];
    int keys[S];
    srand(time(NULL));
    for(int i=0;i<N;i++){
        a[i]=rand() % M;
    }

    for(int i=0;i<S;i++){
        keys[i]=rand() % M;
    }
    
    // S=10000 sequential searches
    start = omp_get_wtime();
    c=0;
    for(int i=0;i<S;i++)  {  
        int pos = seq_search(a,N,keys[i]);
        if (pos!=-1)
            c++;
    }
    finish = omp_get_wtime();
    printf("Using sequential search, found %d times (%.2f)\n", c, finish-start);

    // S=10000 parallel searches
    start = omp_get_wtime();
    c=0;
    for(int i=0;i<S;i++)  {  
        int pos = par_search(a,N,keys[i]);
        if (pos!=-1)
            c++;
    }
    finish = omp_get_wtime();
    printf("Using parallel search, found %d times (%.2f)\n", c, finish-start);
}

int seq_search(int* a, int n, int key){
    for(int i=0;i<n;i++)
        if (a[i]==key)
            return i;
    return -1;
}

int par_search(int* a, int n, int key){
    int pos=-1;
    #pragma omp parallel for
    for(int i=0;i<n;i++)
        if (a[i]==key)
            pos = i;
    return pos;
}
