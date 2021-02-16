# Παραδείγματα με Makefiles

Ο κώδικας έχει σπάσει στα ακόλουθα 4 αρχεία τα οποία θα πρέπει να μεταγλωττιστούν και να συνδεθούν έτσι ώστε να προκύψει το τελικό εκτελέσιμο.

* [functions.h](functions.h)
* [hello.c](hello.c)
* [factorial.c](factorial.c)
* [main.c](main.c)

H έξοδος της εκτέλεσης του προγράμματος σε όλες τις περιπτώσεις που ακολουθούν είναι η ακόλουθη:

```bash
hello
The factorial of 5 is 120
```

## 1. Απευθείας μεταγλώττιση και εκτέλεση από το shell

```bash
gcc factorial.c hello.c main.c -o hello
./hello
```

## 2. Μεταγλώττιση μέσω ενός shell script και εκτέλεση από το shell

* [hello.sh](hello.sh)

```bash
sh hello.sh
./hello
```

ή πρώτα μετατροπή του shell script σε εκτελέσιμο και μετά εκτέλεση του απευθείας

```bash
chmod +x hello.sh
./hello.sh
./hello
```

## 3. Μεταγλώττιση χρησιμοποιώντας ένα απλό makefile

* [mf1.mk](mf1.mk)

```bash
make -f mf1.mk
./hello
```

## 4. Χρήση ενός makefile για τη μεταγλώττιση καθώς και τη διαγραφή object files και εκτελέσιμου αρχείου

* [mf2.mk](mf2.mk)

```bash
make -f mf2.mk
./hello
make -f mf2.mk clean
```

## 5. Χρήση ενός πληρέστερου makefile

* [mf3.mk](mf3.mk)

```bash
make -f mf3.mk
make -f mf3.mk run
make -f mf3.mk clean
```

## 6. Χρήση ενός συντομότερου makefile

* [makefile](makefile)

```bash
make
make run
make clean
```