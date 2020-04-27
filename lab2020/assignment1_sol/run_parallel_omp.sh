#!/bin/bash
gcc-9 parallel_count_primes2_omp.c -o parallel_count_primes2_omp -fopenmp -lm
numbers=(1000000 2000000 4000000 8000000)
threads=(2 4 8 16 32 64)
for n in "${numbers[@]}"
do
    for t in "${threads[@]}"
    do
        echo "size = " $n "threads = " $t
        ./parallel_count_primes2_omp $n $t
        echo "**************************************"
    done
done