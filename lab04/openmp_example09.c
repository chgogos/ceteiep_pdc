#include <stdio.h>
#include <omp.h>

#define N 10000000


// άθροισμα ακέραιων τιμών από το 1 μέχρι το Ν
int main() {
	long long sum = 0;

	// 1. Σειριακά
	for (int i = 1; i <= N; i++)
		sum += i;
	printf("1. Sum is %lld\n", sum);

	// 2. Παράλληλα αλλά λάθος αποτέλεσμα λόγω έλλειψης συγχρονισμού
	sum = 0;
	#pragma omp parallel for
	for (int i = 1; i <= N; i++)
		sum += i;
	printf("2. Sum is %lld (should be incorrect)\n", sum); // WRONG VALUE NO SYNCHRONIZATION

	// 3. Παράλληλα με χρήση αριθμού κάθε νήματος για μοίρασμα της δουλειάς
	sum = 0;
	#pragma omp parallel
	{
		int T = omp_get_num_threads();
		int rank_id = omp_get_thread_num();
		long long my_sum = 0;
		for (int i = rank_id * N / T + 1; i <= (rank_id + 1) * N / T; i++)
			my_sum += i;
		printf("3. Partial sum by thread %d is %lld\n", rank_id, my_sum);
		#pragma omp critical
		sum += my_sum;
	}
	printf("3. Sum is %lld\n", sum);

	// 4. Παράλληλα με reduction
	sum = 0;
	#pragma omp parallel for reduction(+: sum)
	for (int i = 1; i <= N; i++)
		sum += i;
	printf("4. Sum is %lld\n", sum);

	// 5. Παράλληλα με reduction και εμφάνιση των αποτελεσμάτων κάθε νήματος
	sum = 0;
	#pragma omp parallel reduction(+: sum)
	{
		long long my_sum = 0;
		#pragma omp for
		for (int i = 1; i <= N; i++)
			my_sum += i;
		printf("5. Partial sum by thread %d is %lld\n", omp_get_thread_num(), my_sum);
		sum = my_sum;
	}
	printf("5. Sum is %lld\n", sum);

	return 0;
}