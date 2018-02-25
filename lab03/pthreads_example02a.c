#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// άνω όριο για τους τυχαίους πραγματικούς αριθμούς που θα παραχθούν
#define a 10.0

/*
 Πίνακας Α με διαστάσεις m x n
 Διάνυσμα x με n στοιχεία
 Σειριακός πολλαπλασιασμός του πίνακα Α με το διάνυσμα x

 ./pthreads_example02a 100000 1000
*/
void generate_random_data(double **A, double *x, int m, int n) {
  srand(time(NULL));
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      A[i][j] = a * (double)rand() / (double)RAND_MAX;
  for (int i = 0; i < n; i++)
    x[i] = a * (double)rand() / (double)RAND_MAX;
}

int main(int argc, char **argv) {
  double **A;
  double *x, *y;
  int m, n;

  if (argc != 3) {
    printf("Usage: %s m n\n", argv[0]);
    exit(-1);
  }
  m = atoi(argv[1]);
  n = atoi(argv[2]);

  x = (double *)malloc(sizeof(double) * n);
  // για επιπλέον τρόπους δέσμευσης δισδιάστατου πίνακα στη C δείτε
  // http://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
  A = (double **)malloc(sizeof(double *) * m);
  for (int i = 0; i < m; i++)
    A[i] = (double *)malloc(sizeof(double) * n);
  y = (double *)malloc(sizeof(double) * m);

  generate_random_data(A, x, m, n);

  for (int i = 0; i < m; i++) {
    y[i] = 0.0;
    for (int j = 0; j < n; j++)
      y[i] += A[i][j] * x[j];
  }

  // εκτύπωση των 10 πρώτων αποτελεσμάτων
  int k = m;
  if (k > 10)
    k = 10;
  for (int i = 0; i < k; i++)
    printf("%d -> %.2f\n", i, y[i]);

  free(x);
  free(y);
  for (int i = 0; i < m; i++)
    free(A[i]);
  free(A);
  return 0;
}