#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    sem_t *sem = sem_open("/mysem", O_CREAT, 0644, 0);
    pid_t pid = fork();
    int *arr = (int *)malloc(10 * sizeof(int));

    if (pid == 0)
    {
        // Child process
        sem_wait(sem); // Wait for the parent to signal
        printf("semaphore, Child PID : %d\n", getpid());
        for (int i = 0; i < 10; ++i)
        {
            arr[i] = i * 4;
            printf("Child Process arr[%d] : %d\n", i, arr[i]);
        }
        free(arr);
        sem_close(sem);
        sem_unlink("/mysem");
    }
    else
    {
        // Parent process
        printf("semaphore, Parent PID: %d, Child PID: %d\n", getpid(), pid);
        for (int i = 0; i < 10; ++i)
        {
            arr[i] = i * 2;
            printf("Parent process arr[%d] : %d\n", i, arr[i]);
        }
        sem_post(sem); // Signal the child to start
        free(arr);
        sem_close(sem);
    }
    return 0;
}
