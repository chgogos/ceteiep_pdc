# Παράλληλα και Κατανεμημένα Συστήματα (Θεωρία και εργαστήριο)

Τμήμα Πληροφορικής και Τηλεπικοινωνιών Πανεπιστημίου Ιωαννίνων

Γκόγκος Χρήστος @ Άρτα 2021

Τελευταία ενημέρωση: 20/4/2021

## Συγγράμματα μαθήματος

* Εισαγωγή στον παράλληλο προγραμματισμό, Peter Pacheco, Εκδόσεις Κλειδάριθμος, 2011 
  * [Σελίδα του βιβλίου](http://www.klidarithmos.gr/eisagwgh-ston-parallhlo-programmatismo)
  * [Σελίδα της αγγλικής έκδοσης του βιβλίου](https://www.cs.usfca.edu/~peter/ipp/)
* Παράλληλα συστήματα και προγραμματισμός, Δημακόπουλος Βασίλειος, ΚΑΛΛΙΠΟΣ, 2016
  * [Σελίδα του βιβλίου στον Κάλλιπο](https://repository.kallipos.gr/handle/11419/3209)

## Εργασίες

* [Πρώτη εργασία (pThreads)](./assignment2021_1/index.md)
* [Δεύτερη εργασία (OpenMP)](./assignment2021_1/index.md)

## Α. Θεωρία

* Κεφάλαια 1 έως και 5 από το "Εισαγωγή στον παράλληλο προγραμματισμό" του P. Pacheco.
* Java Concurrency
* Apache Hadoop και Apache Spark

## Β. Εργαστήριο

Θέματα που καλύπτονται στο εργαστήριο: pThreads, OpenMP, Java concurrency και MPI

### 1. pThreads

[Παραδείγματα με pThreads](./lab_pthreads/README.md)

### 2. OpenMP

[Παραδείγματα OpenMP](./lab_omp/README.md)


### 3. MPI

Παραδείγματα με MPI

---

## Σύνδεσμοι

* pThreads
  * [Livermore computing center - Προγραμματισμός Νημάτων POSIX](http://pdplab.it.uom.gr/teaching/llnl-gr/POSIX%20Threads%20Programming.htm)
* OpenMP
  * [Livermore computing center - OpenMP](http://pdplab.it.uom.gr/teaching/llnl-gr/OpenMP.html)
  * [OpenMP Reference Card 5.0](./resources/OpenMPRef-5.0-111802.pdf)
* MPI 
  * [Livermore computing center - Διεπαφή Μεταβίβασης Μηνυμάτων](http://pdplab.it.uom.gr/teaching/llnl-gr/Message%20Passing%20Interface%20%28MPI%29.htm)
  * [MPI tutorials](http://mpitutorial.com/tutorials/)
  * [An introduction to the MPI using C](http://condor.cc.ku.edu/~grobe/docs/intro-MPI-C.shtml)
* Java concurrency
  * [Introduction to Java Programming using java - Chapter 12 Threads and Multiprocessing](http://math.hws.edu/javanotes/c12/index.html)
  * [DZone Java concurrency - reference card](https://dzone.com/refcardz/core-java-concurrency)

---

* [Αρχείο υλικού από το ακαδημαϊκό έτος 2019-2020](./archive/README.md)


<!-- ## Εργαστήριο (υλικό εαρινού εξαμήνου 2019-2020)

* [Κώδικας εργαστηρίου](./lab2020/)
* [Εκφωνήσεις ασκήσεων](./lab2020/lab_exercises.md)
* [Λυμένα θέματα προετοιμασίας για την εξέταση του εργαστηρίου (pdf)](./exams_preparation/lab_exams_prep.pdf)


### Εργαστήριο (POSIX threads)

* [Παραδείγματα με POSIX threads (pdf)](./docs/03.POSIX%20threads.pdf)
  * [Κώδικας παραδειγμάτων](./lab02/README.md)
* [Ασκήσεις εργαστηρίου 2 (pdf)](./docs/04.ΑΣΚΗΣΕΙΣ%20ΕΡΓΑΣΤΗΡΙΟΥ%202%20(POSIX%20THREADS).pdf)
  * [Λύσεις ασκήσεων εργαστηρίου 2](./lab02x/README.md)

### Εργαστήριο (java concurrency)

* [Παραδείγματα java concurrency (pdf)](./docs/05.JAVA%20CONCURRENCY.pdf)
  * [Κώδικας παραδειγμάτων](./lab03/README.md)
* [Ασκήσεις εργαστηρίου 3 (pdf)](./docs/06.ΑΣΚΗΣΕΙΣ%20ΕΡΓΑΣΤΗΡΙΟΥ%203%20(JAVA%20CONCURRENCY).pdf)
  * [Λύσεις ασκήσεων εργαστηρίου 3](./lab03x/README.md)

### Εργαστήριο (OpenMP)

* [Παραδείγματα με OpenMP (pdf)](./docs/07.OPENMP.pdf)
  * [Κώδικας παραδειγμάτων](./lab04/README.md)
* [Ασκήσεις εργαστηρίου 4 (pdf)](./docs/09.ΑΣΚΗΣΕΙΣ%20ΕΡΓΑΣΤΗΡΙΟΥ%204%20(OPENMP).pdf)
  * [Λύσεις ασκήσεων εργαστηρίου 4](./lab04x/README.md)
* [Παραδείγματα OpenMP(Tim Mattson) (pdf)](./docs/08.OPENMP(Tim%20Mattson).pdf)
  * [Κώδικας για τα επιπλέον παραδείγματα](./lab04ma/README.md)

### Εργαστήριο (MPI)

* Εγκατάσταση MPICH2
  * [Εγκατάσταση MPICH2 σε UBUNTU 18.04](https://www.howtoinstall.me/ubuntu/18-04/mpich/)
  * [Εγκατάσταση MPICH2 σε UBUNTU](https://mpitutorial.com/tutorials/installing-mpich2/)  
  * [Οδηγίες εγκατάστασης WSL (Windows Subsystem for Linux) for Windows και MPICH2 στο WSL](https://spyros3000.gitlab.io/uoi-pdc/WSL-MPICH-Instructions.html)  
* [Παραδείγματα με MPI (pdf)](./docs/10.MPI.pdf)
  * [Κώδικας παραδειγμάτων](./lab05/README.md)
* [Ασκήσεις εργαστηρίου 5 (pdf)](./docs/11.ΑΣΚΗΣΕΙΣ%20ΕΡΓΑΣΤΗΡΙΟΥ%205%20(MPI).pdf)
  * [Λύσεις ασκήσεων εργαστηρίου 5](./lab05x/README.md) -->

