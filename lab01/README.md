## Διεργασίες POSIX στη C

### Παράδειγμα 0
Απλό παράδειγμα με την fork().

* [fork_example0.c](fork_example0.c)


Μεταγλώττιση και εκτέλεση

```bash
$ gcc -Wall fork_example0.c -o fork_example0
$ ./fork_example0
```

Έξοδος

```bash
A. value of x is 5 as reported by process:6962
B. value of x is 6 as reported by process:6962
B. value of x is 4 as reported by process:6963
```

### Παράδειγμα 1
Παράδειγμα με 2 διεργασίες που η διεργασία γονέας περιμένει τη διεργασία παιδί για να ολοκληρώσει την εκτέλεσή της.

* [fork_example1.c](fork_example1.c)

Μεταγλώττιση και εκτέλεση

$ gcc -Wall fork_example1.c -o fork_example1
$ ./fork_example1


Έξοδος

```bash	
A. value of x is 5
B. value of x is 5
D. parent process 7047 with child 7048, value of x is 4
B. value of x is 5
C. child process 7048 having parent 7047, value of x is 6
hello
E. value of x is 4
```

Προσοχή: Η γραμμή Ε δεν εμφανίζεται από τη διεργασία "παιδί" διότι έχει πλέον αντικατασταθεί ο κώδικας που εκτελείται από τη διεργασία αυτή μέσω της execl από το πρόγραμμα echo. 

### Παράδειγμα 2
Παράδειγμα επικοινωνίας διεργασιών μέσω pipe.

* [fork_example2.c](fork_example2.c)

Μεταγλώττιση και εκτέλεση

```bash
gcc -Wall fork_example2.c -o fork_example2
./fork_example2
```

Έξοδος 

```bash
child process got data Greetings from parent process
```

### Παράδειγμα 3

* [fork_example3.c](fork_example3.c)
* [makefile3](makefile3)

Μεταγλώττιση και εκτέλεση

```bash	
make -f makefile3
make -f makefile3 run
```

Έξοδος

```bash
./fork_example3 56
Parent process: Collatz sequence for 56: 28 14 7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
Child process: Collatz sequence for 57: 172 86 43 130 65 196 98 49 148 74 37 112 56 28 14 7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
```

---

* [makefile](makefile)

Και τα 3 παραδείγματα μπορούν να μεταγλωττιστούν μαζί με την εντολή:

```bash	
make
```
