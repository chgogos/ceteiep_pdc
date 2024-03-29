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

---

## Ασκήσεις (και λύσεις)

**Άσκηση 1**

Να γράψετε πρόγραμμα που να δημιουργεί 5 νήματα. Το κάθε νήμα απλά να εμφανίζει έναν τυχαίο ακέραιο αριθμό στο διάστημα \[1,100\] και να τερματίζει. Γράψτε τις εντολές μεταγλώττισης και εκτέλεσης του προγράμματος.

* [pthreads_exercise01.c](./pthreads_exercise01.c)

**Άσκηση 2**

Να γράψετε πρόγραμμα που να δέχεται ως παράμετρο γραμμής εντολών έναν ακέραιο αριθμό και να εμφανίζει το άθροισμα όλων των θετικών ακεραίων που είναι μικρότεροι ή ίσοι του αριθμού αυτού (οι σχετικές μεταβλητές να δηλωθούν ως τύπου long long).  Για τον υπολογισμό του αθροίσματος να χρησιμοποιεί νήματα. Ο αριθμός των νημάτων θα περνά  επίσης ως παράμετρος γραμμής εντολών. Υπολογίστε το άθροισμα των πρώτων  10.000.000 ακέραιων αριθμών χρησιμοποιώντας 4 νήματα. Γράψτε τις εντολές μεταγλώττισης και εκτέλεσης του προγράμματος.

* [pthreads_exercise02a.c](./pthreads_exercise02a.c)
* [pthreads_exercise02b.c](./pthreads_exercise02b.c)


**Άσκηση 3**

Να γράψετε πρόγραμμα που να γεμίζει με τυχαίες ακέραιες τιμές στο διάστημα \[1,10\] δύο διανύσματα 1.000 θέσεων το καθένα και να υπολογίζει το εσωτερικό τους γινόμενο <http://mathinsight.org/dot_product_matrix_notation>. Για τον υπολογισμό του εσωτερικού γινομένου η εργασία να «σπάσει»  σε 4 νήματα. 

* [pthreads_exercise03.c](./pthreads_exercise03.c)


**Άσκηση 4**

Σε έναν κύκλο με ακτίνα r η επιφάνεια του είναι πr^2 ενώ η επιφάνεια του περιγεγραμμένου στον κύκλο  τετραγώνου είναι 4r^2. Εξετάζοντας το λόγο της επιφάνειας του κύκλου προς την επιφάνεια του τετραγώνου προκύπτει ότι θα πρέπει να ισούται με π/4. Αν πραγματοποιηθεί ένα πείραμα στο οποίο θα μετρούνται πόσα από ένα σύνολο τυχαίων σημείων πέφτουν εντός του κύκλου τότε ο λόγος του πλήθους των τυχαίων σημείων εντός του κύκλου προς το συνολικό πλήθος σημείων θα πρέπει και αυτός να ισούται με π/4. Να γράψετε πρόγραμμα που να υπολογίζει χρησιμοποιώντας τον τρόπο που αναφέρθηκε τον αριθμό π. Η εργασία να μοιράζεται σε έναν αριθμό νημάτων. Εκτελέστε το πρόγραμμα για πλήθος 300.000.000 σημείων και για 8 νήματα.

* [pthreads_exercise04a.c](./pthreads_exercise04a.c)
* [pthreads_exercise04b.c](./pthreads_exercise04b.c)


**Άσκηση 5**

Δίνεται ο ακόλουθος κώδικας ο οποίος υπολογίζει με τη βοήθεια δύο νημάτων το άθροισμα των στοιχείων του πίνακα Α. Το πρώτο thread αθροίζει τα πρώτα 5 στοιχεία και το δεύτερο thread τα υπόλοιπα 5 στοιχεία του πίνακα. Συμπληρώστε τον κώδικα στα σημεία 1 έως και 9  αντιστοιχίζοντας τα a έως g έτσι ώστε να είναι κρίσιμο τμήμα η εντολή sum+=q και στα δύο νήματα.

```
a)	pthread_create(&thread2, NULL, thread2_work, NULL);
b)	pthread_mutex_lock(&mx);
c)	pthread_mutex_unlock(&mx);
d)	pthread_mutex_t mx; 
e)	pthread_mutex_init(&mx, NULL);
f)	pthread_mutex_destroy(&mx);
g)	pthread_join(thread2, NULL);
```

Κώδικας που πρέπει να συμπληρωθεί.

```
#include <stdio.h>
#include <pthread.h>

int A[10]={1,2,3,4,5,6,7,8,9,10};
int sum = 0;
// [1]
void* thread1_work(void* arg){
	int q=0;
	for(int i=0;i<5;i++)
		q += A[i];
	// [2]
	sum += q;
	// [3]
	return NULL;
}
void* thread2_work(void* arg){
	int q=0;
	for(int i=5;i<10;i++)
		q += A[i];
	// [4]
	sum += q;
	// [5]
	return NULL;
}
int main(){
	pthread_t thread1, thread2;
	// [6]
	pthread_create(&thread1, NULL, thread1_work, NULL);
	// [7]
	pthread_join(thread1, NULL);
	// [8]
	printf("the sum is %d\n", sum);
	// [9]
	return 0;
}
```
* [pthreads_exercise05.c](./pthreads_exercise05.c)

**Άσκηση 6**

Μετατρέψτε τον κώδικα της άσκησης 5 έτσι ώστε να χρησιμοποιεί αναμονή σε εκρήγορση (busy wait) αντί για mutex έτσι ώστε να πετύχει το ίδιο αποτέλεσμα.

* [pthreads_exercise06.c](./pthreads_exercise06.c)


--- 

## Εργασίες

* 2019-2020
  * [Εκφώνηση](https://chgogos.github.io/ceteiep_pdc/archive/lab2020/assignment1/20200224_assignment1.pdf)
    * [serial_count_primes.c](https://chgogos.github.io/ceteiep_pdc/archive/lab2020/assignment1/serial_count_primes.c)
    * [timer.h](https://chgogos.github.io/ceteiep_pdc/archive/lab2020/assignment1/timer.h)
  * [Λύση](https://chgogos.github.io/ceteiep_pdc/archive/lab2020/assignment1_sol/)