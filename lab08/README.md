# C++11 multithreading

Τα ακόλουθα παραδείγματα βασίζονται στο <https://www.classes.cs.uchicago.edu/archive/2013/spring/12300-1/labs/lab6/>

## Example01

Δημιουργία νήματος, εμφάνιση μηνύματος μέσα από τον κώδικα του νήματος, μήνυμα από το κύριο νήμα όταν ολοκληρώσει την εκτέλεσή του το νήμα.

* [example01a.cpp](./example01a.cpp)
* [example01b.cpp](./example01b.cpp) με lambda συνάρτηση

## Example02

Άθροιση τιμών από 20 νήματα 

* [example02a.cpp](./example02a.cpp) χρήση καθολικής μεταβλητής, λάθος αποτελέσματα (race condition)
* [example02b.cpp](./example02b.cpp) χρήση ref(...), λάθος αποτελέσματα (race condition)
* [example02c.cpp](./example02c.cpp) επίλυση race condition με mutex
* [example02d.cpp](./example02d.cpp) επίλυση race condition με atomic variable

έλεγχος αποτελεσμάτων εκτελέωντας πολλές φορές το κάθε εκτελέσιμο:

```bash
    for i in {1..100}; do ./example02a; done | sort | uniq -c 
    for i in {1..100}; do ./example02b; done | sort | uniq -c 
    for i in {1..100}; do ./example02c; done | sort | uniq -c 
    for i in {1..100}; do ./example02d; done | sort | uniq -c 
```

## Example03

Προγραμματισμός νημάτων μέσω tasks (υψηλότερου επιπέδου)

async (promise + future)

* [example03.cpp](./example03.cpp) 

## Example 04

Συγχρονισμός νημάτων

* [example04a.cpp](./example04a.cpp) χωρίς συγχρονισμό
* [example04b.cpp](./example04b.cpp) με συγχρονισμό χρησιμοποιώντας condition variable