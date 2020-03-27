#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define N 10000      // αριθμός σημείων στο καρτεσιανό επίπεδο
#define DISTANCE 0.1 // απόσταση σημείων
#define T 2

struct point
{
    double x, y;
};

int counter = 0;
struct point points[N];
pthread_mutex_t mutex;

void *work(void *tid)
{
    long id = (long)tid;
    int from = id * N / T;
    int to = (id + 1) * N / T;
    int c = 0;
    for (int i = from; i < to; i++)
        for (int j = i + 1; j < N; j++)
        {
            double x = points[i].x - points[j].x;
            double y = points[i].y - points[j].y;
            if (sqrt(pow(x, 2) + pow(y, 2)) < DISTANCE)
            {
                c++;
            }
        }
    pthread_mutex_lock(&mutex);
    counter += c;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main()
{
    long seed = 1821L; // time(NULL)
    srand(seed);
    for (int i = 0; i < N; i++)
    {
        points[i].x = (double)rand() / RAND_MAX * 2.0 - 1.0;
        points[i].y = (double)rand() / RAND_MAX * 2.0 - 1.0;
    }

    pthread_t handles[T];
    pthread_mutex_init(&mutex, NULL);
    for (long tid = 0; tid < T; tid++)
        pthread_create(&handles[tid], NULL, work, (void *)tid);

    for (long tid = 0; tid < T; tid++)
        pthread_join(handles[tid], NULL);

    printf("Number of points: %d\n", counter);
    pthread_mutex_destroy(&mutex);
}

/* έξοδος
Number of points: 377905
*/