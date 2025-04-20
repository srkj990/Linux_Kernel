#include <pthread.h>
#include <stdio.h>

// Shared resource
int shared_data = 0;

// Mutex to protect shared resource
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //PTHREAD_MUTEX_INITIALIZER macro is used to initialize the mutex with default attributes
/* Equiavalent to the following code
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL); 
*/
void *thread_func(void *arg)
{
    // Acquire lock on mutex
    pthread_mutex_lock(&mutex);

    // Access shared resource
    shared_data++;

    printf("shared_data : %d\n", shared_data);

    // Release lock on mutex
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main()
{
    // Create threads
    pthread_t threads[10];
    for (int i = 0; i < 10; i++)
    {
        pthread_create(&threads[i], NULL, thread_func, NULL);
    }

    // Wait for threads to finish
    for (int i = 0; i < 10; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}


#if 0

    Mutexes are used to protect shared resources from concurrent access by multiple threads.

    1. pthread_mutex_init(): Initializes a mutex.

        This function initializes a mutex, preparing it for use. It takes two arguments: 
        a pointer to the mutex to be initialized and an attribute object that specifies the mutex's behavior.
        
        int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);

    2. pthread_mutex_lock(): Acquires a lock on a mutex, blocking if it's already locked.

        This function acquires a lock on a mutex, blocking the calling thread if the mutex is already locked by another thread. 
        Once the lock is acquired, the mutex is considered "locked" and other threads will block if they try to lock it.

        int pthread_mutex_lock(pthread_mutex_t *mutex);

    3. pthread_mutex_unlock(): Releases a lock on a mutex.

        This function releases a lock on a mutex, allowing other threads to acquire the lock.
        If multiple threads are waiting for the lock, one of them will be unblocked and allowed to acquire the lock.

        int pthread_mutex_unlock(pthread_mutex_t *mutex);

    4. pthread_mutex_destroy(): Destroys a mutex.

        This function destroys a mutex, releasing any system resources associated with it.
        The mutex should not be used after it has been destroyed.

        int pthread_mutex_destroy(pthread_mutex_t *mutex);


    pthread_mutex_init() is used to initialize the mutex with a custom attribute object that specifies a recursive mutex type.
    pthread_mutex_t mutex;
    pthread_mutexattr_t attr;

    // Initialize the mutex attribute object
    pthread_mutexattr_init(&attr);

    // Set the mutex type to recursive
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);

    // Initialize the mutex with the custom attribute object
    pthread_mutex_init(&mutex, &attr);

    // Destroy the mutex attribute object
    pthread_mutexattr_destroy(&attr);
    
#endif