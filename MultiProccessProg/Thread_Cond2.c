#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int data_ready = 0;

void *producer(void *arg)
{
    // Produce data
    printf("Producing data...\n");
    data_ready = 1;

    // Signal the consumer thread
    pthread_mutex_lock(&mutex);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void *consumer(void *arg)
{
    // Wait for data to be ready
    pthread_mutex_lock(&mutex);
    while (!data_ready)
    {
        pthread_cond_wait(&cond, &mutex);
    }
    pthread_mutex_unlock(&mutex);

    // Consume data
    printf("Consuming data...\n");

    return NULL;
}

int main()
{
    pthread_t producer_thread, consumer_thread;

    // Create threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Destroy condition variable
    pthread_cond_destroy(&cond);

    return 0;
}

#if 0
pthread_cond_init(): Initializes a condition variable.
pthread_cond_wait(): Waits on a condition variable.
pthread_cond_signal(): Signals a condition variable.
pthread_cond_broadcast(): Signals all threads waiting on a condition variable.
pthread_cond_destroy(): Destroys a condition variable.

#endif
