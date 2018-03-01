## Παραδείγματα με Makefiles 

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

### 1. Απευθείας μεταγλώττιση και εκτέλεση από το shell 

```bash
gcc factorial.c hello.c main.c -o hello
./hello
```

### 2. Μεταγλώττιση μέσω ενός shell script και εκτέλεση από το shell

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

### 3. Μεταγλώττιση χρησιμοποιώντας ένα απλό makefile

* [Makefile1](Makefile1)

```bash
make -f Makefile1
./hello
```

### 4. Χρήση ενός makefile για τη μεταγλώττιση καθώς και τη διαγραφή object files και εκτελέσιμου αρχείου

* [Makefile2](Makefile2)

```bash
make -f Makefile2
./hello
make -f Makefile2 clean
```

### 5. Χρήση ενός πληρέστερου makefile

* [Makefile3](Makefile3)

```bash
make -f Makefile3
make -f Makefile3 run
make -f Makefile2 clean
```