## Παραδείγματα με Makefiles 

* [hello.c](hello.c)
* [factorial.c](factorial.c)
* [main.c](main.c)


### 1. Απευθείας μεταγλώττιση και εκτέλεση από το shell 

```bash
	$ gcc factorial.c hello.c main.c -o hello
	$ ./hello
```

Έξοδος

```bash
	hello
	The factorial of 5 is 120
```

### 2. Μεταγλώττιση μέσω ενός shell script και εκτέλεση από το shell

```bash
	$ sh hello.sh
	$ ./hello
```

ή 

```bash
	$ chmod +x hello.sh
	$ ./hello.sh
	$ ./hello
```

### 3. Μεταγλώττιση χρησιμοποιώντας ένα απλό makefile

```bash
	$ make -f Makefile1
	$ ./hello
```

### 4. Χρήση ενός makefile για τη μεταγλώττιση καθώς και τη διαγραφή object files και εκτελέσιμου αρχείου

```bash
	$ make -f Makefile2
	$ ./hello
	$ make -f Makefile2 clean	
```

### 5. Χρήση ενός καλύτερου makefile

```bash
	$ make -f Makefile3
	$ make -f Makefile3 run	
	$ make -f Makefile2 clean
```