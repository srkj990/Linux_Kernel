#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 8
#define INCREMENTS_PER_THREAD 10

pthread_mutex_t lock;
pthread_cond_t cond;
int shared_counter = 0;
int turn = 0; // Tracks which thread's turn it is

void *increment_counter(void *arg)
{
    int thread_id = *(int *)arg;

    pthread_mutex_lock(&lock);
    while (turn != thread_id)
    {
        pthread_cond_wait(&cond, &lock);
    }

    // Each thread increments the counter fully before passing control
    for (int i = 0; i < INCREMENTS_PER_THREAD; i++)
    {
        shared_counter++;
    }

    printf("Counter value: %d ", shared_counter);
    printf("Thread %d finished its turn\n", thread_id);
    // Pass control to the next thread
    turn++;
    pthread_cond_broadcast(&cond);

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Initialize the mutex and condition variable
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    printf("Initial Counter value: %d\n", shared_counter);

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, increment_counter, &thread_ids[i]);
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Print final counter value
    printf("Final Counter value: %d\n", shared_counter);

    // Destroy the mutex and condition variable
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    return 0;
}


#if 0

pthread_cond_init(): Initializes a condition variable.
pthread_cond_wait(): Waits on a condition variable.
pthread_cond_signal(): Signals a condition variable.
pthread_cond_broadcast(): Signals all threads waiting on a condition variable.
pthread_cond_destroy(): Destroys a condition variable.

pthread_cond_signal() unblocks at least one thread waiting on a condition variable, while
pthread_cond_broadcast() unblocks all threads waiting on that same variable. 
#endif
