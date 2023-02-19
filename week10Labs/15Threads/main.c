#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

int count = 0;

//work function
void* increment(void *a)
{
    for (int i=1; i<=1000000; i++)
    count++;

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

//the problem with a 1M is that when the threads are trying to all
// increment the count at the same only one thread succeeds 
//lack of syncronisation between the threads while using the same resource "counter"