# Ασκήσεις εργαστηρίου 

## pThreads: 27/3/2020

Γράψτε ένα πρόγραμμα που να δημιουργεί 30.000 σημεία σε ένα καρτεσιανό επίπεδο με τιμές για τον άξονα των τετμημένων και τον άξονα των τεταγμένων από -1.0 έως και 1.0. Να υπολογίζει όλες τις αποστάσεις μεταξύ δύο οποιονδήποτε σημείων και να μετρά το πλήθος από αυτές που είναι μικρότερες από 0.1. Γράψτε πρώτα μια σειριακή έκδοση του προγράμματος και στη συνέχεια μια παράλληλη έκδοση που να χρησιμοποιεί 4 νήματα.

Λύση:

* [timer.h](./lab_ex1/timer.h) κώδικας από το [IPP](https://www.cs.usfca.edu/~peter/ipp/) για χρονομέτρηση.
* [cartesian_serial.c](./lab_ex1/cartesian_serial.c) σειριακός κώδικας 
* [cartesian_parallel0.c](./lab_ex1/cartesian_parallel0.c) απόπειρα επίλυσης με παράλληλο κώδικα (δεν λειτουργεί σωστά καθώς δεν υπάρχει συγχρονισμός των νημάτων έτσι ώστε να αποφεύγεται η ταυτόχρονη ενημέρωση της καθολικής μεταβλητής counter)
* [cartesian_parallel1.c](./lab_ex1/cartesian_parallel1.c) τοπικός μετρητής για κάθε νήμα, χωρίς συγχρονισμό (επικίνδυνο)
* [cartesian_parallel2.c](./lab_ex1/cartesian_parallel2.c) τοπικός μετρητής για κάθε νήμα, συγχρονισμός νημάτων με busy wait
* [cartesian_parallel3.c](./lab_ex1/cartesian_parallel3.c) τοπικός μετρητής για κάθε νήμα, συγχρονισμός νημάτων με mutex
* [cartesian_parallel4.c](./lab_ex1/cartesian_parallel4.c) τοπικός μετρητής για κάθε νήμα, συγχρονισμός νημάτων με semaphore

## pThreads: 3/4/2020

Θέματα Α1, Α2 και A3 από το <https://chgogos.github.io/ceteiep_pdc/exams_preparation/lab_exams_prep_19.pdf>.

Παραλλαγές εκφωνήσεων του θέματος Α1 και οι λύσεις τους:

* [prepare_pthreads01](../exams_preparation/prepare_pthreads01.c)
* [prepare_pthreads01b](../exams_preparation/prepare_pthreads01b.c)
* [prepare_pthreads01c](../exams_preparation/prepare_pthreads01c.c)
* [prepare_pthreads01d](../exams_preparation/prepare_pthreads01d.c)

Λύση θέματος Α2

* [prepare_pthreads02](../exams_preparation/prepare_pthreads02.c)

Λύση θέματος Α3

* [prepare_pthreads03](../exams_preparation/prepare_pthreads03.c)

## OpenMP: 10/4/2020

Θέματα B1, B2 και B3 από το <https://chgogos.github.io/ceteiep_pdc/exams_preparation/lab_exams_prep_19.pdf>.

Λύση θέματος B1

* [prepare_omp01](../exams_preparation/prepare_omp01.c)

Λύση θέματος B2

* [prepare_omp02](../exams_preparation/prepare_omp02.c)

Λύση θέματος B3

* [prepare_omp03](../exams_preparation/prepare_omp03.c)
