# Λύση άσκησης 1 (pThreads)

* [Πλήρης κώδικας](./)

* [runs.pdf](./runs.pdf)
* [runs.xlsx](./runs.xlsx)

* Σειριακός κώδικας υπολογισμού πλήθους πρώτων αριθμών [serial_count_primes.c](./serial_count_primes.c)

```bash
$ gcc serial_count_primes.c -o serial_count_primes -lm
$ ./serial_count_primes
Number of primes = 283146
The code to be timed took 4.965120e+00 seconds
```

* Σειριακός κώδικας υπολογισμού πλήθους πρώτων αριθμών με ορίσματα γραμμής εντολών [serial_count_primes2.c](./serial_count_primes2.c)

```bash
$ gcc serial_count_primes2.c -o serial_count_primes2 -lm
$ ./serial_count_primes2 4000000
Number of primes = 283146
The code to be timed took 4.651419e+00 seconds
```

* shell script για μαζική εκτέλεση παραδειγμάτων [run_serial.sh](./run_serial.sh)

```bash
$ ./run_serial.sh
size =  1000000
Number of primes = 78498
The code to be timed took 6.934540e-01 seconds
**************************************
size =  2000000
Number of primes = 148933
The code to be timed took 1.920685e+00 seconds
**************************************
size =  4000000
Number of primes = 283146
The code to be timed took 4.942949e+00 seconds
**************************************
size =  8000000
Number of primes = 539777
The code to be timed took 1.312780e+01 seconds
**************************************
```

* Παράλληλος κώδικας υπολογισμού πλήθους πρώτων αριθμών με δύο νήματα [parallel_count_primes1.c](./parallel_count_primes1.c)

```bash
$ gcc parallel_count_primes1.c -o parallel_count_primes1 -lm -lpthread
$ ./parallel_count_primes1
Number of primes = 283146
The code to be timed took 3.130204e+00 seconds
```

* Παράλληλος κώδικας υπολογισμού πλήθους πρώτων αριθμών με ορίσματα γραμμής εντολών για το πλήθος των τιμών και το πλήθος των νημάτων [parallel_count_primes2.c](./parallel_count_primes2.c)

```bash
$ gcc parallel_count_primes2.c -o parallel_count_primes2 -lm -lpthread
$ ./parallel_count_primes2 4000000 4
Number of primes = 283146
The code to be timed took 2.326161e+00 seconds
```

* shell script για μαζική εκτέλεση παραδειγμάτων [run_parallel.sh](./run_parallel.sh)

```bash
$ ./run_parallel.sh
size =  1000000 threads =  2
Number of primes = 78498
The code to be timed took 4.548130e-01 seconds
**************************************
size =  1000000 threads =  4
Number of primes = 78498
The code to be timed took 3.241041e-01 seconds
**************************************
size =  1000000 threads =  8
Number of primes = 78498
The code to be timed took 2.937071e-01 seconds
**************************************
size =  1000000 threads =  16
Number of primes = 78498
The code to be timed took 2.845800e-01 seconds
**************************************
size =  1000000 threads =  32
Number of primes = 78498
The code to be timed took 2.830162e-01 seconds
**************************************
size =  1000000 threads =  64
Number of primes = 78498
The code to be timed took 2.824630e-01 seconds
**************************************
size =  2000000 threads =  2
Number of primes = 148933
The code to be timed took 1.238416e+00 seconds
**************************************
size =  2000000 threads =  4
Number of primes = 148933
The code to be timed took 8.527441e-01 seconds
**************************************
size =  2000000 threads =  8
Number of primes = 148933
The code to be timed took 7.627320e-01 seconds
**************************************
size =  2000000 threads =  16
Number of primes = 148933
The code to be timed took 7.567720e-01 seconds
**************************************
size =  2000000 threads =  32
Number of primes = 148933
The code to be timed took 7.541730e-01 seconds
**************************************
size =  2000000 threads =  64
Number of primes = 148933
The code to be timed took 7.425129e-01 seconds
**************************************
size =  4000000 threads =  2
Number of primes = 283146
The code to be timed took 3.165742e+00 seconds
**************************************
size =  4000000 threads =  4
Number of primes = 283146
The code to be timed took 2.184148e+00 seconds
**************************************
size =  4000000 threads =  8
Number of primes = 283146
The code to be timed took 2.057417e+00 seconds
**************************************
size =  4000000 threads =  16
Number of primes = 283146
The code to be timed took 1.986049e+00 seconds
**************************************
size =  4000000 threads =  32
Number of primes = 283146
The code to be timed took 2.018217e+00 seconds
**************************************
size =  4000000 threads =  64
Number of primes = 283146
The code to be timed took 1.973663e+00 seconds
**************************************
size =  8000000 threads =  2
Number of primes = 539777
The code to be timed took 8.304104e+00 seconds
**************************************
size =  8000000 threads =  4
Number of primes = 539777
The code to be timed took 5.870622e+00 seconds
**************************************
size =  8000000 threads =  8
Number of primes = 539777
The code to be timed took 5.353379e+00 seconds
**************************************
size =  8000000 threads =  16
Number of primes = 539777
The code to be timed took 5.280513e+00 seconds
**************************************
size =  8000000 threads =  32
Number of primes = 539777
The code to be timed took 5.297541e+00 seconds
**************************************
size =  8000000 threads =  64
Number of primes = 539777
The code to be timed took 5.263103e+00 seconds
**************************************
```

## Extra (επίλυση του ίδιου προβλήματος με OpenMP)

* Παράλληλος κώδικας υπολογισμού πλήθους πρώτων αριθμών με ορίσματα γραμμής εντολών για το πλήθος των τιμών και το πλήθος των νημάτων [parallel_count_primes2_omp.c](./parallel_count_primes2_omp.c)

```bash
$ gcc parallel_count_primes2_omp.c -o serial_count_primes2_omp
$ ./parallel_count_primes2_omp 4000000 4
```

* shell script για μαζική εκτέλεση παραδειγμάτων [run_parallel_omp.sh](./run_parallel_omp.sh)

```bash
$ ./run_parallel_omp.sh
size =  1000000 threads =  2
Number of primes = 78498
The code to be timed took 3.441739e-01 seconds
**************************************
size =  1000000 threads =  4
Number of primes = 78498
The code to be timed took 2.827880e-01 seconds
**************************************
size =  1000000 threads =  8
Number of primes = 78498
The code to be timed took 2.755799e-01 seconds
**************************************
size =  1000000 threads =  16
Number of primes = 78498
The code to be timed took 2.806752e-01 seconds
**************************************
size =  1000000 threads =  32
Number of primes = 78498
The code to be timed took 2.766922e-01 seconds
**************************************
size =  1000000 threads =  64
Number of primes = 78498
The code to be timed took 2.841141e-01 seconds
**************************************
size =  2000000 threads =  2
Number of primes = 148933
The code to be timed took 8.670309e-01 seconds
**************************************
size =  2000000 threads =  4
Number of primes = 148933
The code to be timed took 8.115380e-01 seconds
**************************************
size =  2000000 threads =  8
Number of primes = 148933
The code to be timed took 8.459060e-01 seconds
**************************************
size =  2000000 threads =  16
Number of primes = 148933
The code to be timed took 7.779450e-01 seconds
**************************************
size =  2000000 threads =  32
Number of primes = 148933
The code to be timed took 7.480390e-01 seconds
**************************************
size =  2000000 threads =  64
Number of primes = 148933
The code to be timed took 7.305639e-01 seconds
**************************************
size =  4000000 threads =  2
Number of primes = 283146
The code to be timed took 2.361985e+00 seconds
**************************************
size =  4000000 threads =  4
Number of primes = 283146
The code to be timed took 2.254352e+00 seconds
**************************************
size =  4000000 threads =  8
Number of primes = 283146
The code to be timed took 2.184584e+00 seconds
**************************************
size =  4000000 threads =  16
Number of primes = 283146
The code to be timed took 2.177921e+00 seconds
**************************************
size =  4000000 threads =  32
Number of primes = 283146
The code to be timed took 2.258473e+00 seconds
**************************************
size =  4000000 threads =  64
Number of primes = 283146
The code to be timed took 2.205220e+00 seconds
**************************************
size =  8000000 threads =  2
Number of primes = 539777
The code to be timed took 6.279564e+00 seconds
**************************************
size =  8000000 threads =  4
Number of primes = 539777
The code to be timed took 5.578374e+00 seconds
**************************************
size =  8000000 threads =  8
Number of primes = 539777
The code to be timed took 5.375680e+00 seconds
**************************************
size =  8000000 threads =  16
Number of primes = 539777
The code to be timed took 5.398041e+00 seconds
**************************************
size =  8000000 threads =  32
Number of primes = 539777
The code to be timed took 5.407638e+00 seconds
**************************************
size =  8000000 threads =  64
Number of primes = 539777
The code to be timed took 5.508062e+00 seconds
**************************************
```
