#!/bin/bash
gcc-9 serial_count_primes2.c -o serial_count_primes2 -lm
numbers=(1000000 2000000 4000000 8000000)
for n in "${numbers[@]}"
do
    echo "size = " $n
    ./serial_count_primes2 $n
    echo "**************************************"
done