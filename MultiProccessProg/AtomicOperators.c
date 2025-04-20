#include <stdatomic.h>
#include <threads.h>

atomic_int atomic_counter = 0;

int thread_func(void *arg)
{
    for (int i = 0; i < 100000; i++)
    {
        atomic_fetch_add(&atomic_counter, 1);
    }
    return 0;
}