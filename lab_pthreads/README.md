# POSIX Threads

## ΕΡΓΑΣΤΗΡΙΟ 1

Ανίχνευση χαρακτηριστικών μεταγλωττιστή.

* [lc00_test_machine.c](./lc00_test_machine.c)
* [timer.h](./timer.h) για χρονομέτρηση

```
$ gcc lc00_test_machine.c -o lc00_test_machine
$ ./lc00_test_machine
size of int = 4
size of long = 8
size of long long = 8
size of void = 1
size of void* = 8
size of intptr_t = 8
RAND_MAX = 2147483647
INT_MAX = 2147483647
INT_MIN = -2147483648
LONG_MAX = 9223372036854775807
LONG_MIN = -9223372036854775808
ULONG_MAX = 18446744073709551615
ULLONG_MAX = 18446744073709551615
gcc detected version 9.2
Time elapsed for spawning 100 threads: 8.327961e-03
```

Σειριακός κώδικας που υπολογίζει το άθροισμα ακεραίων από το 1 μέχρι και το Ν (Ν=10000).

* [lc00_serial.c](./lc00_serial.c)

```
$ gcc lc00_serial.c -o lc00_serial
$ ./lc00_serial
50005000
```

Παράδειγμα με pThreads. Υπολογισμός αθροίσματος ακεραίων τιμών από το 1 μέχρι και το Ν (Ν=10000) χρησιμοποιώντας Τ νήματα (Τ=2). Το ένα νήμα υπολογίζει το άθροισμα 1 + 2 + ... + Ν/2 ενώ το άλλο νήμα υπολογίζει το άθροισμα Ν/2+1 + Ν/2+2 + ... + Ν. Το κύριο νήμα αναλαμβάνει την πρόσθεση των αθροισμάτων που υπολογίζουν τα νήματα.

Απλοϊκή έκδοση, ξεχωριστή συνάρτηση για κάθε νήμα.

* [lc02_pthreads.c](./lc02_pthreads.c) 

```
$ gcc lc02_pthreads.c -o lc02_pthreads -lpthread
$ ./lc02_pthreads
Process A computes sum = 12502500
Process B computes sum = 37502500
50005000
```

Έκδοση που λειτουργεί και με περισσότερα από 2 threads.

* [lc02_pthreads1.c](./lc02_pthreads1.c) 

Έκδοση που λειτουργεί και με περισσότερα από 2 threads (αλλαγή στον τρόπο με τον οποίο περνά το αναγνωριστικό νήματος στη συνάρτηση που θα εκτελέσει το νήμα).

* [lc02_pthreads2.c](./lc02_pthreads2.c) 

Έκδοση που δέχεται τον αριθμό νημάτων ως **παράμετρο γραμμής εντολών (command line argument)** .

* [lc02_pthreads3.c](./lc02_pthreads3.c) 

```
$ gcc lc02_pthreads3.c -o lc02_pthreads3 -lpthread
$ ./lc02_pthreads3 10
```

Κώδικας υπολογισμού y = A * x (δίνεται ο δισδιάστατος πίνακας Α και το διάνυσμα x και ζητείται ο υπολογισμός του διανύσματος x)

* [lc03_pthreads5.c](./lc03_pthreads5.c) 

---

## ΕΡΓΑΣΤΗΡΙΟ 2 (Συγχρονισμός νημάτων)

Κώδικες που επιδεικνύουν την αναγκαιότητα συγχρονισμού στον παράλληλο και ταυτόχρονο προγραμματισμό.

Ένα σύνολο νημάτων πραγματοποιούν τον ίδιο αριθμό μοναδιαίων αυξήσεων και μοναδιαίων μειώσεων στην κοινόχρηστη μεταβλητή counter που αρχικοποιείται στην τιμή 0. Η τελική τιμή της μεταβλητής counter θα έπρεπε να είναι 0 αλλά λόγω "συνθήκης ανταγωνισμού" δεν προκύπτει το σωστό αποτέλεσμα.

* [lc03_pthreads6.c](./lc03_pthreads6.c)

Επίλυση του προβλήματος με busy_wait (για 4 νήματα).

* [lc03_pthreads6_busy_wait.c](./lc03_pthreads6_busy_wait.c)

Το busy wait είναι "επικίνδυνο" αν πρόκειται να ζητηθεί βελτιστοποίηση κατά τη μεταγλώττιση. Το πρόβλημα μπορεί να επιλυθεί με τη χρήση volatile μεταβλητών.

* [lc03_pthreads6_busy_wait_volatile.c](./lc03_pthreads6_busy_wait_volatile.c)

Επίλυση του προβλήματος με αμοιβαίο αποκλεισμό (mutex).

* [lc03_pthreads6_mutex.c](./lc03_pthreads6_mutex.c)

Επίλυση του προβλήματος με σημαφόρους.

* [lc03_pthreads6_semaphore.c](./lc03_pthreads6_semaphore.c)

Επίλυση του προβλήματος του προηγούμενου εργαστηρίου με mutex.

* [lc02_pthreads4.c](./lc02_pthreads4.c)

---

## ΕΡΓΑΣΤΗΡΙΟ 3 (φράγματα - μεταβλητές συνθήκης)

**Χρησιμότητες των φραγμάτων**

* Αναγκαιότητα εφαρμογής υπολογισμών σε φάσεις (π.χ. υπολογισμοί Φάσης Α που πρέπει να ολοκληρωθεί από κάποια threads πριν τα νήματα προχωρήσουν σε μια δεύτερη φάση υπολογισμών)
* Χρονομέτρηση κώδικα
* Διευκόλυνση αποσφαλμάτωσης

### Ένα απλό παράδειγμα με φράγμα

10 νήματα "κοιμούνται" για κάποια δευτερόλεπτα το καθένα εμφανίζοντας μήνυμα για το χρονικό διάστημα του "ύπνου τους". Μόνο όταν όλα τα νήματα "ξυπνήσουν", τότε το καθένα θα πρέπει να εμφανίσει μήνυμα για το ότι "ξύπνησε".

Απόπειρα λύσης χωρίς φράγμα.

* [lc04_simple_no_barrier.c](./lc04_simple_no_barrier.c)

Λύση με φράγμα pthread_barrier_t.

* [lc04_simple_builtin_barrier.c](./lc04_simple_builtin_barrier.c)

Λύση με custom υλοποίηση φράγματος καθώς ορισμένες υλοποιήσεις pthreads δεν έχουν υλοποίηση των φραγμάτων. 

* [lc04_simple_custom_barrier.c](./lc04_simple_custom_barrier.c)

### Ένα δεύτερο παράδειγμα χρησιμότητας των φραγμάτων

Έστω ότι 10 νήματα πρέπει πρώτα να προσθέσουν από μια μονάδα σε μια κοινόχρηστη μεταβλητή και μετά το καθένα να διπλασιάσει τη μεταβλητή.

Κώδικας χωρίς barrier (λάθος αποτελέσματα)

* [lc04_no_barrier.c](./lc04_no_barrier.c)

Χρήση ενσωματωμένου φράγματος (εφόσον το υποστηρίζει ο μεταγλωττιστής)

* [lc04_builtin_barrier.c](./lc04_builtin_barrier.c)

Custom υλοποίηση φράγματος με mutex και αναμονή σε εκρήγορση

* [lc04_custom_barrier1.c](./lc04_custom_barrier1.c)

Custom υλοποίηση φράγματος με conditional variable

* [lc04_custom_barrier2.c](./lc04_custom_barrier2.c)

### Παράδειγμα με conditional variable

Σενάριο προβλήματος: Τρία νήματα Τ1, Τ2 και Τ3. Το νήμα Τ1 θα πρέπει να περιμένει να ξεκινήσουν τα νήματα Τ2 και Τ3 έτσι ώστε να ξεκινήσει. Τα νήματα Τ2 και Τ3 θα πρέπει να περιμένουν το Τ1 να τα ειδοποιήσει ότι μπορούν να συνεχίσουν την εκτέλεσή τους. 

* [lc04_conditional_var.c](./lc04_conditional_var.c)

```bash
$ gcc lc04_conditional_var.c - o lc04_conditional_var -lpthread
$ lc04_conditional_var
T3:start
T3:wait T1 to finish
T2:start
T2:wait T1 to finish
T1:start
T1:work
T1:broadcast
T1:finish
T2:work
T2:finish
T3:work
T3:finish
```