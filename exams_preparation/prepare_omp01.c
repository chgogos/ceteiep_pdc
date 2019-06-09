/*
Δημιουργία 4 νημάτων, εμφάνιση των ακόλουθων μηνυμάτων ανά νήμα
για το νήμα 0 το μήνυμα "Hello"
για το νήμα 1 το μήνυμα "Hi"
για το νήμα 2 το μήνυμα "Geia"
για το νήμα 3 το μήνυμα "Hallo"
*/

#include <stdio.h>
#include <omp.h>

int main(){
    #pragma omp parallel num_threads(4)
    {
        int id = omp_get_thread_num();
        if(id==0)
            printf("Hello\n");
        else if(id==1)
            printf("Hi\n");
        else if(id==2)
            printf("Geia\n");
        else if(id==3)
            printf("Hallo\n");
    }
}