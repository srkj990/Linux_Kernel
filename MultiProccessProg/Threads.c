#include <pthread.h>
#include <stdio.h>

void *thread_function(void *arg)
{
    printf("Thread running on core %ld\n", (long)arg);
    return NULL;
}

int main()
{
    pthread_t threads[4];

    for (long i = 0; i < 4; i++)
    {
        pthread_create(&threads[i], NULL, thread_function, (void *)i);
    }

    for (int i = 0; i < 4; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

#if 0
Thread Creation and Management:

1. pthread_create(): Creates a new thread.
    
    int pthread_create(pthread_t *thread, pthread_attr_t *attr, void *(*start_routine)(void*), void *arg);
        
        thread: A pointer to a pthread_t variable that will store the ID of the newly created thread.
        
        attr: A pointer to a pthread_attr_t structure that defines the attributes of the new thread. If NULL, default attributes are used.
        
        start_routine: A function pointer to the routine that the new thread will execute.
        
        arg: A pointer to the argument that will be passed to the start_routine function.

    Example :

        #include <pthread.h>

        void* my_thread_function(void* arg) {
            // Thread code here
            return NULL;
        }

        int main() {
            pthread_t thread;
            pthread_create(&thread, NULL, my_thread_function, NULL);
            return 0;
        }

2. pthread_join(): Waits for a thread to terminate.
    
    int pthread_join(pthread_t thread, void **retval);
        
        thread: The ID of the thread to wait for.
        
        retval: A pointer to a void* variable that will store the return value of the thread.

    Example: 

        #include <pthread.h>

        void* my_thread_function(void* arg) 
        {
            // Thread code here
            printf("Thread running on core %ld\n", (long)arg);
            return NULL;
        }

        int main() 
        {
            pthread_t thread;
            pthread_create(&thread, NULL, my_thread_function, NULL);
            void* retval;
            pthread_join(thread, &retval);
            return 0;
        }
3. pthread_exit(): Terminates the calling thread.

    void pthread_exit(void *retval);
        
        retval: A pointer to the return value of the thread.

    Example : 

        #include <pthread.h>

        void* my_thread_function(void* arg) 
        {
            // Thread code here
            pthread_exit(NULL);
            return NULL; // Not reached
        }

        int main() 
        {
            pthread_t thread;
            pthread_create(&thread, NULL, my_thread_function, NULL);
            return 0;
        }

4. pthread_detach(): Detaches a thread, allowing its resources to be freed immediately upon termination.
   
    int pthread_detach(pthread_t thread);

        thread: The ID of the thread to detach.
    
    Example : 

        #include <pthread.h>

        void* my_thread_function(void* arg) 
        {
            // Thread code here
            return NULL;
        }

        int main() 
        {
            pthread_t thread;
            pthread_create(&thread, NULL, my_thread_function, NULL);
            pthread_detach(thread);
            return 0;
        }


#endif