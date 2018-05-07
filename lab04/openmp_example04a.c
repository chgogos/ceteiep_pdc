#include <stdio.h>
#include <omp.h>

// Δομές διαμοιρασμού εργασίας (single, sections, for)

int main() {
  int i;

#pragma omp parallel num_threads(5)
  {
    // ο ακόλουθος κώδικας θα εκτελεστεί από όλα τα νήματα
    printf("Hi from thread %d\n", omp_get_thread_num());

// ο ακόλουθος κώδικας θα εκτελεστεί από ένα μόνο τυχαίο νήμα
#pragma omp single
    printf("The thread chosen for single execution is %d\n",
           omp_get_thread_num());

// δύο τυχαία νήματα θα εκτελέσουν από ένα από τα ακόλουθα sections
#pragma omp sections
    {
#pragma omp section
      { printf("Section A was executed by %d\n", omp_get_thread_num()); }
#pragma omp section
      { printf("Section B was executed by %d\n", omp_get_thread_num()); }
    }

// οι 10 επαναλήψεις της for θα μοιραστούν από 2 σε κάθε ένα από τα 5 νήματα
#pragma omp for
    for (i = 0; i < 10; i++)
      printf("Iteration %d is given to thread %d\n", i, omp_get_thread_num());
  }
}