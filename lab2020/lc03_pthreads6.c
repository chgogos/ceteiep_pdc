// Κάθε νήμα πραγματοποιεί τον ίδιο αριθμό μοναδιαίων αυξήσεων και μοναδιαίων μειώσεων
// στην κοινόχρηστη μεταβλητή counter.
// Η τελική τιμή της μεταβλητής counter θα έπρεπε να είναι μηδέν αλλά λόγω "συνθήκης ανταγωνισμού"
// δεν λαμβάνεται το σωστό αποτέλεσμα .

#include <stdio.h>
#include <pthread.h>

#define T 10

int counter = 0; // shared variable

void *work(void *id)
{
    long tid = (long)id;
    printf("Thread %ld is working\n", tid);
    for (int i = 0; i < 1000000; i++)
    {
        if (i % 2 == 0)
            counter++;
        else
            counter--;
    }
    return NULL;
}

int main()
{
    pthread_t thread_handles[T];
    for (long tid = 0; tid < T; tid++)
    {
        pthread_create(&thread_handles[tid], NULL, work, (void *)tid);
    }
    for (int i = 0; i < T; i++)
    {
        pthread_join(thread_handles[i], NULL);
    }
    printf("counter = %d\n", counter);
}

/* Έξοδος
Thread 1 is working
Thread 2 is working
Thread 0 is working
Thread 3 is working
Thread 5 is working
Thread 6 is working
Thread 7 is working
Thread 9 is working
Thread 8 is working
Thread 4 is working
counter = -5366
*/ 