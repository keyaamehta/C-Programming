#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

int count = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
//work function
void* increment(void *a)
{
        pthread_mutex_lock(&lock);
    for (int i=1; i<=1000000; i++)
    {
        count++;
    }
        pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{  
    pthread_t thr[15];

    for (int i=0; i<15; i++)
    {
        pthread_create(&thr[i], NULL, increment, NULL); //create 15 threads
    }
    for (int i=0; i<15; i++)
    {
        pthread_join(thr[i], NULL); //the parent waiting unti each thread terminates
    }
    printf("\n%d\n", count);
    return 0;
}
