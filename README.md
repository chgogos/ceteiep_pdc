# Παράλληλα και Κατανεμημένα Συστήματα (Θεωρία και εργαστήριο)

Τμήμα Μηχανικών Πληροφορικής ΤΕΙ Ηπείρου

## Θεωρία

Παράλληλο υλικό και λογισμικό, προγραμματισμός κοινόχρηστης μνήμης, προγραμματισμός κατανεμημένης μνήμης (MPI) 
### Συγγράμματα

* Εισαγωγή στον παράλληλο προγραμματισμό, Peter Pacheco, Εκδόσεις Κλειδάριθμος, 2011 <http://www.klidarithmos.gr/eisagwgh-ston-parallhlo-programmatismo>
* Παράλληλα συστήματα και προγραμματισμός, Δημακόπουλος Βασίλειος, ΚΑΛΛΙΠΟΣ, 2016 <https://repository.kallipos.gr/handle/11419/3209>
* Introduction to Parallel Computing, Ananth Grama, George Karypis, Vipin Kumar and Anshul Gupta, PEARSON, Second Edition, 2003

### Ενδιαφέρουσες ιστοσελίδες

* [Livermore computing center - high performance computing](https://hpc.llnl.gov/training/tutorials)
* [Introduction to parallel programming](https://computing.llnl.gov/tutorials/parallel_comp/)
* [CSinParallel](https://csinparallel.org/index.html)

## Εργαστήριο

POSIX processes, POSIX threads, Java concurrency, OpenMP, MPI

### Εργαστήριο 1 (POSIX processes)

* [Εισαγωγή στα makefiles (pdf)](./docs/00.makefiles.pdf)
* [makefiles](./lab00/README.md)
* [Εισαγωγή στα POSIX processes (pdf)](./docs/01.POSIX%20processes.pdf)
* [POSIX processes](./lab01/README.md)
* [Ασκήσεις εργαστηρίου 1 (pdf)](./docs/02.ΑΣΚΗΣΕΙΣ%20ΕΡΓΑΣΤΗΡΙΟΥ%201%20(POSIX%20PROCESSES).pdf)
* [Λύσεις ασκήσεων εργαστηρίου 1](./lab01x/README.md)

#### Επιπλέον υλικό για POSIX processes

* <https://www.ibm.com/developerworks/aix/library/au-spunix_sharedmemory/index.html>

### Εργαστήριο 2 (POSIX threads)

* [Παραδείγματα με POSIX threads (pdf)](./docs/03.POSIX%20threads.pdf)
* [Κώδικας παραδειγμάτων](./lab02/README.md)
* [Ασκήσεις εργαστηρίου 2 (pdf)](./docs/04.ΑΣΚΗΣΕΙΣ%20ΕΡΓΑΣΤΗΡΙΟΥ%202%20(POSIX%20THREADS).pdf)
* [Λύσεις ασκήσεων εργαστηρίου 2](./lab02x/README.md)
* [Udacity - Georgia Tech - Advanced OS (pthreads examples)](./lab02gt/README.md)

#### Επιπλέον υλικό για POSIX threads

* <https://computing.llnl.gov/tutorials/pthreads/>
* [Basic use of pthreads](https://www.ibm.com/developerworks/library/l-pthred/index.html)
* <http://www.csc.villanova.edu/~mdamian/threads/posixthreadslong.html>

### Εργαστήριο 3 (java concurrency)

* [Παραδείγματα java concurrency (pdf)](./docs/05.JAVA%20CONCURRENCY.pdf)
* [Κώδικας παραδειγμάτων](./lab03/README.md)
* [Ασκήσεις εργαστηρίου 3 (pdf)](./docs/06.ΑΣΚΗΣΕΙΣ%20ΕΡΓΑΣΤΗΡΙΟΥ%203%20(JAVA%20CONCURRENCY).pdf)
* [Λύσεις ασκήσεων εργαστηρίου 3](./lab03x/README.md)

#### Επιπλέον υλικό για Java concurrency

* [Java concurrent animated](http://www.jconcurrent.com/), [executable jar](./lab03ca/javaConcurrentAnimated.jar)
* [DZone Java concurrency - reference card](https://dzone.com/refcardz/core-java-concurrency) 
* [Introduction to Java Programming using java - Chapter 12 Threads and Multiprocessing](http://math.hws.edu/javanotes/c12/index.html)
* [Udemy Java Multithreading MOOC](https://www.udemy.com/java-multithreading/)

### Εργαστήριο 4 (OpenMP)

OpenMP

### Εργαστήριο 5 (MPI)

MPI

<!-- Δημιουργία όλων των εκτελέσιμων

```bash
bash makeall.sh
```

Διαγραφή όλων των εκτελέσιμων

```bash
bash makeall.sh clean
``` -->
