# POSIX Threads

## Παράδειγμα 0

Δημιουργία 2 νημάτων και εμφάνιση μηνύματος από το καθένα.

* [pthreads_example00a.c](pthreads_example00a.c)

```bash
gcc pthreads_example00a.c -o pthreads_example00a -lpthread
./pthreads_example00a
This is a message from the main thread
This is a message from thread: B
This is a message from thread: A
```

Δημιουργία 10 νημάτων και εμφάνιση μηνύματος από το καθένα.

* [pthreads_example0b.c](pthreads_example00b.c)

```bash
gcc pthreads_example00b.c -o pthreads_example00b -lpthread
./pthreads_example00b
This is a message from the main thread
This is a message from thread: 6
This is a message from thread: 7
This is a message from thread: 8
This is a message from thread: 9
This is a message from thread: 5
This is a message from thread: 4
This is a message from thread: 3
This is a message from thread: 2
This is a message from thread: 1
This is a message from thread: 0
```

## Παράδειγμα 1

Δημιουργία ενός αριθμού νημάτων (ο αριθμός καθορίζεται από το όρισμα γραμμής εντολών) και εμφάνιση μηνύματος που περιέχει τον αριθμό νήματος για κάθε νήμα.

* [pthreads_example01a.c](pthreads_example01a.c)

```bash
gcc pthreads_example01a.c -o pthreads_example01a -lpthread
./pthreads_example01a 4
Hello from thread 0 (opaque thread id: 123145492553728) of 4
Hello from thread 1 (opaque thread id: 123145493090304) of 4
Hello from thread 2 (opaque thread id: 123145493626880) of 4
Hello from the main thread
Hello from thread 3 (opaque thread id: 123145494163456) of 4
```

Δημιουργία 4 νημάτων. Κάθε νήμα "παράγει" έναν αριθμό που τον επιστρέφει στο κύριο νήμα. Εμφανίζονται όλες οι τιμές που παράγονται και επιστρέφονται.

* [pthreads_example01b.c](pthreads_example01b.c)

```bash
gcc pthreads_example01b.c -o pthreads_example01b -lpthread
./pthreads_example01b
Thread 0 produces 23
Thread 1 produces 12
Thread 2 produces 78
Thread 3 produces 90
Thread 0 returns 23
Thread 1 returns 12
Thread 2 returns 78
Thread 3 returns 90
```

## Παράδειγμα 2

Πολλαπλασιασμός ενός πίνακα Α με m γραμμές και n στήλες με ένα διάνυσμα n στοιχείων

* [pthreads_example02a.c](pthreads_example02a.c) (σειριακή λύση)
* [pthreads_example02b.c](pthreads_example02b.c) (παράλληλη λύση)
* [pthreads_example02c.c](pthreads_example02c.c) (παράλληλη λύση με στατικούς πίνακες - απλούστερος κώδικας)

```bash
gcc pthreads_example02a.c -o pthreads_example02a
time ./pthreads_example02a 100000 1000
0 -> 25925.70
1 -> 25116.42
2 -> 24880.10
3 -> 26421.22
4 -> 24739.83
5 -> 24421.85
6 -> 25089.27
7 -> 25201.41
8 -> 25585.28
9 -> 25770.27
./pthreads_example02a 100000 1000  1.22s user 0.29s system 99% cpu 1.520 total
```

```bash
gcc pthreads_example02b.c -o pthreads_example02b
time ./pthreads_example02b 100000 1000 4
0 -> 24343.15
1 -> 24505.63
2 -> 24254.85
3 -> 24339.83
4 -> 25015.67
5 -> 24040.35
6 -> 24510.99
7 -> 24588.91
8 -> 25797.50
9 -> 24254.58
./pthreads_example02b 100000 1000 4  1.52s user 0.27s system 141% cpu 1.269 total
```

```bash
gcc pthreads_example02c.c -o pthreads_example02c
time ./pthreads_example02c
time ./pthreads_example02c
y[0] = 199238.33
...
y[99999] = 197795.70

real 1m9.398s
user 0m12.236s
sys 0m13.821s
```

### Παράδειγμα 3 (busy wait, mutexes, semaphores)

Υπολογισμός του π ως ένα άθροισμα σειράς (βλ. Pacheco σελ 229)

* [pthreads_example03a.c](pthreads_example03a.c) (σειριακός κώδικας, παράλληλος κώδικας χωρίς συγχρονισμό)
* [pthreads_example03b.c](pthreads_example03b.c) (παράλληλος κώδικας με busy wait)
* [pthreads_example03c.c](pthreads_example03c.c) (παράλληλος κώδικας με mutex)
* [pthreads_example03d.c](pthreads_example03d.c) (παράλληλος κώδικας με semaphores)

```bash
gcc pthreads_example03a.c -o pthreads_example03a -lpthread
./pthreads_example03a
Pi value computed using 1000000 terms and 10 threads  = 3.144836482933
Pi value computed using 1000000 terms and serial code = 3.141591653590
```

```bash
gcc pthreads_example03b.c -o pthreads_example03b -lpthread
./pthreads_example03b
Pi value computed using 1000000 terms and 10 threads (busy wait) = 3.141591653590
```

```bash
gcc pthreads_example03c.c -o pthreads_example03c -lpthread
./pthreads_example03c
Pi value computed using 1000000 terms and 10 threads (mutex) = 3.141591653590
```

```bash
gcc pthreads_example03d.c -o pthreads_example03d -lpthread
./pthreads_example03d
Pi value computed using 1000000 terms and 10 threads (semaphore) = 3.141591653590
```

## Παράδειγμα 4 (condition variables - μεταβλητές συνθήκης)

Μεταβλητές υπό συνθήκη. Εννέα threads παράγουν από έναν αριθμό (π.χ. τον αριθμό 1) και τον τοποθετούν σε διαφορετικές θέσεις ενός κοινόχρηστου πίνακα. Ένα επιπλέον thread λειτουργεί ως καταναλωτής των τιμών που παρήγαγαν τα νήματα παραγωγοί τις οποίες και διπλασιάζει. Το κύριο πρόγραμμα αθροίζει όλες τις τιμές του κοινόχρηστου πίνακα.

* [pthreads_example04a.c](pthreads_example04a.c)

```bash
gcc pthreads_example04a.c -o pthreads_example04a -lpthread
./pthreads_example04a
Thread 0 produces value 1
Thread 1 produces value 1
Thread 2 produces value 1
Thread 3 produces value 1
Thread 4 produces value 1
Thread 5 produces value 1
Thread 6 produces value 1
Thread 7 produces value 1
Thread 8 produces value 1
Consumer thread 9 doubled all values
Main: The sum is 18
```

Ένα thread παράγει μια τιμή και εννέα άλλα threads περιμένουν έτσι ώστε να παραχθεί και στη συνέχεια να την εμφανίσουν.

```bash
gcc pthreads_example04b.c -o pthreads_example04b -lpthread
./pthreads_example04b
Producer thread 0 is busy
Thread 0 produced shared value 42
Consumer thread 2 reads shared value 42
Consumer thread 3 reads shared value 42
Consumer thread 1 reads shared value 42
Consumer thread 4 reads shared value 42
Consumer thread 5 reads shared value 42
Consumer thread 6 reads shared value 42
Consumer thread 7 reads shared value 42
Consumer thread 8 reads shared value 42
Consumer thread 9 reads shared value 42
Main: shared value 42
```

## Παράδειγμα 5 (barriers - κλήσεις φραγής)

* [pthreads_example05a.c](pthreads_example05a.c)

10 νήματα ξεκινούν και καθένα από αυτά εμφανίζει πρώτα το μήνυμα Phase A και μετά το μήνυμα Phase B. Θέλουμε πρώτα να εμφανιστούν όλα τα μηνύματα Α και μετά όλα τα μηνύματα Β.

```bash
gcc -pthread pthreads_example05a.c -o pthreads_example05a -lpthread
./pthreads_example05a
Thread 0 phase A
Thread 1 phase A
Thread 2 phase A
Thread 4 phase A
Thread 5 phase A
Thread 6 phase A
Thread 7 phase A
Thread 8 phase A
Thread 3 phase A
Thread 9 phase A
Thread 4 phase B
Thread 1 phase B
Thread 6 phase B
Thread 5 phase B
Thread 8 phase B
Thread 7 phase B
Thread 3 phase B
Thread 0 phase B
Thread 2 phase B
Thread 9 phase B
```


* [pthreads_example05b.c](pthreads_example05b.c)

Μια κοινόχρηστη μεταβλητή με αρχική τιμή 0 πρώτα αυξάνεται κατά 1 από 10 νήματα και εφόσον ολοκληρωθεί η φάση αυτή καθένα από τα 10 νήματα διπλασιάζει την τιμή της.

* 1+1+...+1=10
* 10\*2\*2\*...\*2 = 10240

```bash
gcc -pthread pthreads_example05b.c -o pthreads_example05b -lpthread
./pthreads_example05b
Thread 0 added 1 to the shared value, shared value=1
Thread 1 added 1 to the shared value, shared value=2
Thread 2 added 1 to the shared value, shared value=3
Thread 3 added 1 to the shared value, shared value=4
Thread 4 added 1 to the shared value, shared value=5
Thread 5 added 1 to the shared value, shared value=6
Thread 6 added 1 to the shared value, shared value=7
Thread 7 added 1 to the shared value, shared value=8
Thread 8 added 1 to the shared value, shared value=9
Thread 9 added 1 to the shared value, shared value=10
Thread 0 doubled shared value, shared value=20
Thread 8 doubled shared value, shared value=40
Thread 1 doubled shared value, shared value=80
Thread 2 doubled shared value, shared value=160
Thread 3 doubled shared value, shared value=320
Thread 4 doubled shared value, shared value=640
Thread 5 doubled shared value, shared value=1280
Thread 6 doubled shared value, shared value=2560
Thread 7 doubled shared value, shared value=5120
Thread 9 doubled shared value, shared value=10240
The final result is 10240
```
