#include <stdatomic.h>
#include <stdio.h>
#include <pthread.h>

atomic_int flag = 0;
int data = 0;

void *writer_thread(void *arg)
{
    data = 42; // Write data
    atomic_store_explicit(&flag, 1, memory_order_release);
    return NULL;
}

void *reader_thread(void *arg)
{
    while (atomic_load_explicit(&flag, memory_order_acquire) == 0)
    {
        // Spin until flag is set
    }
    printf("Data: %d\n", data); // Guaranteed to see 42
    return NULL;
}
int main()
{
    pthread_t writer, reader;
    pthread_create(&writer, NULL, writer_thread, NULL);
    pthread_create(&reader, NULL, reader_thread, NULL);
    pthread_join(writer, NULL);
    pthread_join(reader, NULL);
    return 0;
}