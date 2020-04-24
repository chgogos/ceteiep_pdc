#!/bin/bash
gcc parallel_count_primes2.c -o parallel_count_primes2 -lpthread -lm
numbers=(1000000 2000000 4000000 8000000)
threads=(2 4 8 16 32 64)
for n in "${numbers[@]}"
do
    for t in "${threads[@]}"
    do
        echo "size = " $n "threads = " $t
        ./parallel_count_primes2 $n $t
        echo "**************************************"
    done
done