#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 4

pthread_barrier_t barrier; // Barrier variable

void *worker(void *arg)
{
    int thread_id = *(int *)arg;

    // Stage 1: Each thread does some work
    printf("Thread %d: Stage 1 completed.\n", thread_id);
    sleep(1); // Simulate work

    // Synchronization point
    pthread_barrier_wait(&barrier);

    // Stage 2: Only starts after all threads complete Stage 1
    printf("Thread %d: Proceeding to Stage 2.\n", thread_id);
    sleep(1);

    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Initialize the barrier for NUM_THREADS threads
    pthread_barrier_init(&barrier, NULL, NUM_THREADS);

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, worker, &thread_ids[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Destroy the barrier
    pthread_barrier_destroy(&barrier);

    return 0;
}
#if 0

A pthread barrier is used to synchronize multiple threads at a specific point in execution, 
ensuring that all threads reach a certain point before any of them proceed further.


Thread Synchronization at a Checkpoint

Ensure all threads finish a particular stage before moving forward.

Example: In a multi-stage computation where results from one stage are needed before starting the next.

Parallel Processing Coordination

Useful in parallel algorithms where each thread completes a part of the computation before moving to the next phase.

Work Distribution Across Threads

Helps in data-parallel applications where threads work on chunks of data and must synchronize before the next iteration.
#endif