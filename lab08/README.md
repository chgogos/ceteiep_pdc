# C++11 multithreading

Τα ακόλουθα παραδείγματα βασίζονται στο <https://www.classes.cs.uchicago.edu/archive/2013/spring/12300-1/labs/lab6/>

## Example01

Δημιουργία νήματος, εμφάνιση μηνύματος μέσα από τον κώδικα του νήματος, μήνυμα από το κύριο νήμα όταν ολοκληρώσει την εκτέλεσή του το νήμα.

* [example01a.cpp](./example01a.cpp)

```
    Message from thread 123
    Message from the main thread
```

* [example01b.cpp](./example01b.cpp) με lambda συνάρτηση

```
    Message from thread 123
    Message from the main thread
```

## Example02

Άθροιση τιμών από 20 νήματα (έλεγχος αποτελεσμάτων εκτελώντας πολλές φορές το κάθε εκτελέσιμο)

* [example02a.cpp](./example02a.cpp) χρήση καθολικής μεταβλητής, λάθος αποτελέσματα (race condition)

```bash
    for i in {1..100}; do ./example02a; done | sort | uniq -c 

    1 accum = 17350000
    1 accum = 17850000
    98 accum = 28700000
```

* [example02b.cpp](./example02b.cpp) χρήση ref(...), λάθος αποτελέσματα (race condition)

```bash
    for i in {1..100}; do ./example02b; done | sort | uniq -c 

    1 accum = 17850000
    99 accum = 28700000
```

* [example02c.cpp](./example02c.cpp) επίλυση race condition με mutex

```bash
    for i in {1..100}; do ./example02c; done | sort | uniq -c 

    100 accum = 28700000
```

* [example02d.cpp](./example02d.cpp) επίλυση race condition με atomic variable

```bash
    for i in {1..100}; do ./example02d; done | sort | uniq -c 

    100 accum = 28700000
```

## Example03

Προγραμματισμός νημάτων υψηλότερου επιπέδου (μέσω tasks)

async (promise + future)

* [example03.cpp](./example03.cpp) 

```
    Message 1 from the main thread 
    Message from thread 1 (sleeping for 5 seconds)
    The thread returned 42
    Message 2 from the main thread
```

## Example 04

Συγχρονισμός νημάτων

* [example04a.cpp](./example04a.cpp) χωρίς συγχρονισμό

```
    The value is 100 (incorrect)
```

* [example04b.cpp](./example04b.cpp) με συγχρονισμό χρησιμοποιώντας condition variable

```
    The value is 20 (correct)
```
