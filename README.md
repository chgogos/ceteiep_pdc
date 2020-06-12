# Παράλληλα και Κατανεμημένα Συστήματα (Θεωρία και εργαστήριο)

Τμήμα Πληροφορικής και Τηλεπικοινωνιών Πανεπιστημίου Ιωαννίνων

Γκόγκος Χρήστος @ Άρτα 2020

Τελευταία ενημέρωση: 12/6/2020

* [Ύλη εξέτασης Ιουνίου 2020 για τη θεωρία και το εργαστήριο](./teliki.md)

## Quizzes

* [ΚΠΣ-Θεωρία](https://forms.office.com/Pages/ResponsePage.aspx?id=KqW-CNNaJ0aVSV_zplZ2vipdBmu1BS9Kl7T5PdVBgURUMUlQTFlXR1dIMjg1M0MzQ0hKVDlMNEU4Ui4u)
* [ΚΠΣ-Pthreads](https://forms.office.com/Pages/ResponsePage.aspx?id=KqW-CNNaJ0aVSV_zplZ2vipdBmu1BS9Kl7T5PdVBgURUNU5aQzdNMFkzNVlCUVBHWDRQN0tLOEVSVy4u)
* [ΚΠΣ-OpenMP](https://forms.office.com/Pages/ResponsePage.aspx?id=KqW-CNNaJ0aVSV_zplZ2vipdBmu1BS9Kl7T5PdVBgURUNEtPV1ZZQUZWQ1lIV1gyTjVWSU5EWjlJUC4u)
* [ΚΠΣ-MPI](https://forms.office.com/Pages/ResponsePage.aspx?id=KqW-CNNaJ0aVSV_zplZ2vipdBmu1BS9Kl7T5PdVBgURUOElQT0tXSVBURzlCRUNFQ0lRSVZLVFYxUy4u)
* [ΚΠΣ-Java Concurrency](https://forms.office.com/Pages/ResponsePage.aspx?id=KqW-CNNaJ0aVSV_zplZ2vipdBmu1BS9Kl7T5PdVBgURUQTJCWjFROVE1WVpZSUlORDRYMTlHTFJUUC4u)

## Θεωρία

Παράλληλο υλικό και λογισμικό, προγραμματισμός κοινόχρηστης μνήμης, προγραμματισμός συστημάτων κατανεμημένης μνήμης.

* [Προαιρετικές εργασίες θεωρίας](./docs/ΚΠΣ_ΕΡΓΑΣΙΕΣ_2019-2020.pdf)

### Σύγγραμμα μαθήματος

* Εισαγωγή στον παράλληλο προγραμματισμό, Peter Pacheco, Εκδόσεις Κλειδάριθμος, 2011 <http://www.klidarithmos.gr/eisagwgh-ston-parallhlo-programmatismo>
  * [IPP Book](https://www.cs.usfca.edu/~peter/ipp/)

## Εργαστήριο (υλικό εαρινού εξαμήνου 2019-2020)

POSIX processes, POSIX threads, Java concurrency, OpenMP, MPI.

* [Εργασίες εργαστηρίου](./lab2020/assignments2020.md)
* [Κώδικας εργαστηρίου](./lab2020/)
* [Εκφωνήσεις ασκήσεων](./lab2020/lab_exercises.md)
* [Λυμένα θέματα προετοιμασίας για την εξέταση του εργαστηρίου (pdf)](./exams_preparation/lab_exams_prep.pdf)

### Εργαστήριο (POSIX processes)

* [Εισαγωγή στα makefiles (pdf)](./docs/00.makefiles.pdf)
* [makefiles](./lab00/README.md)
* [Εισαγωγή στα POSIX processes (pdf)](./docs/01.POSIX%20processes.pdf)
* [POSIX processes](./lab01/README.md)
* [Ασκήσεις εργαστηρίου 1 (pdf)](./docs/02.ΑΣΚΗΣΕΙΣ%20ΕΡΓΑΣΤΗΡΙΟΥ%201%20(POSIX%20PROCESSES).pdf)
  * [Λύσεις ασκήσεων εργαστηρίου 1](./lab01x/README.md)
* [Επικοινωνία μεταξύ διεργασιών](https://www.ibm.com/developerworks/aix/library/au-spunix_sharedmemory/index.html)

### Εργαστήριο (POSIX threads)

* [Παραδείγματα με POSIX threads (pdf)](./docs/03.POSIX%20threads.pdf)
  * [Κώδικας παραδειγμάτων](./lab02/README.md)
* [Ασκήσεις εργαστηρίου 2 (pdf)](./docs/04.ΑΣΚΗΣΕΙΣ%20ΕΡΓΑΣΤΗΡΙΟΥ%202%20(POSIX%20THREADS).pdf)
  * [Λύσεις ασκήσεων εργαστηρίου 2](./lab02x/README.md)
* [Udacity - Georgia Tech - Advanced OS (pthreads examples)](./lab02gt/README.md)
* <https://computing.llnl.gov/tutorials/pthreads/>
* [Basic use of pthreads](https://www.ibm.com/developerworks/library/l-pthred/index.html)
* <http://www.csc.villanova.edu/~mdamian/threads/posixthreadslong.html>

### Εργαστήριο (java concurrency)

* [Παραδείγματα java concurrency (pdf)](./docs/05.JAVA%20CONCURRENCY.pdf)
  * [Κώδικας παραδειγμάτων](./lab03/README.md)
* [Ασκήσεις εργαστηρίου 3 (pdf)](./docs/06.ΑΣΚΗΣΕΙΣ%20ΕΡΓΑΣΤΗΡΙΟΥ%203%20(JAVA%20CONCURRENCY).pdf)
  * [Λύσεις ασκήσεων εργαστηρίου 3](./lab03x/README.md)
* [Java concurrent animated](http://www.jconcurrent.com/), [executable jar](./lab03ca/javaConcurrentAnimated.jar)
* [DZone Java concurrency - reference card](https://dzone.com/refcardz/core-java-concurrency)
* [Introduction to Java Programming using java - Chapter 12 Threads and Multiprocessing](http://math.hws.edu/javanotes/c12/index.html)

### Εργαστήριο (OpenMP)

* [Παραδείγματα με OpenMP (pdf)](./docs/07.OPENMP.pdf)
  * [Κώδικας παραδειγμάτων](./lab04/README.md)
* [Ασκήσεις εργαστηρίου 4 (pdf)](./docs/09.ΑΣΚΗΣΕΙΣ%20ΕΡΓΑΣΤΗΡΙΟΥ%204%20(OPENMP).pdf)
  * [Λύσεις ασκήσεων εργαστηρίου 4](./lab04x/README.md)
* [A hands on introduction to OpenMP by Tim Mattson (pdf)](./resources/Intro_To_OpenMP_Mattson.pdf)
* [Παραδείγματα OpenMP(Tim Mattson) (pdf)](./docs/08.OPENMP(Tim%20Mattson).pdf)
  * [Κώδικας για τα επιπλέον παραδείγματα](./lab04ma/README.md)
  * [OpenMP Reference Card 5.0](./resources/OpenMPRef-5.0-111802.pdf)

### Εργαστήριο (MPI)

* [Οδηγίες εγκατάστασης WSL (Windows Subsystem for Linux) for Windows και MPICH2 στο WSL](https://spyros3000.gitlab.io/uoi-pdc/WSL-MPICH-Instructions.html)  
* [Εγκατάσταση MPICH2 σε UBUNTU](https://mpitutorial.com/tutorials/installing-mpich2/)  
* [Παραδείγματα με MPI (pdf)](./docs/10.MPI.pdf)
  * [Κώδικας παραδειγμάτων](./lab05/README.md)
* [Ασκήσεις εργαστηρίου 5 (pdf)](./docs/11.ΑΣΚΗΣΕΙΣ%20ΕΡΓΑΣΤΗΡΙΟΥ%205%20(MPI).pdf)
  * [Λύσεις ασκήσεων εργαστηρίου 5](./lab05x/README.md)
* [MPI tutorials](http://mpitutorial.com/tutorials/)
* [Εισαγωγή στο MPI](http://condor.cc.ku.edu/~grobe/docs/intro-MPI-C.shtml)

-----

## Βιβλία

* Παράλληλα συστήματα και προγραμματισμός, Δημακόπουλος Βασίλειος, ΚΑΛΛΙΠΟΣ, 2016 <https://repository.kallipos.gr/handle/11419/3209>
* Introduction to Parallel Computing, Ananth Grama, George Karypis, Vipin Kumar and Anshul Gupta, PEARSON, Second Edition, 2003

## MOOCs

* [Udemy Java Multithreading MOOC](https://www.udemy.com/java-multithreading/)
* [Python in High Performance Computing](https://www.futurelearn.com/courses/python-in-hpc/2)
* [MPI: A Short Introduction to One-sided Communication](https://www.futurelearn.com/courses/mpi-one-sided)

## Ενδιαφέρουσες ιστοσελίδες

* [Livermore computing center - high performance computing](https://hpc.llnl.gov/training/tutorials)
* [Introduction to parallel programming](https://computing.llnl.gov/tutorials/parallel_comp/)
* [CSinParallel](https://csinparallel.org/index.html)

<!-- Δημιουργία όλων των εκτελέσιμων

```bash
bash makeall.sh
```

Διαγραφή όλων των εκτελέσιμων

```bash
bash makeall.sh clean
``` -->
