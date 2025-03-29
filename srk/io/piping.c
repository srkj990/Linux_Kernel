#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int pipefd[2]; // pipefd[0] = Read end, pipefd[1] = Write end
    pipe(pipefd);
    pid_t pid = fork();
    int *arr = (int *)malloc(10 * sizeof(int));

    if (pid == 0)
    {                     // Child process
        close(pipefd[1]); // Close write end, wait for signal
        char buf;
        read(pipefd[0], &buf, 1); // Wait until parent sends a byte
        printf("Piping, Child PID : %d\n", getpid());
        for (int i = 0; i < 10; ++i)
        {
            arr[i] = i * 4;
            printf("Child Process arr[%d] : %d\n", i, arr[i]);
        }
        close(pipefd[0]);
        free(arr);
    }
    else
    {                     // Parent process
        close(pipefd[0]); // Close read end
        printf("Piping, Parent PID: %d, Child PID: %d\n", getpid(), pid);
        for (int i = 0; i < 10; ++i)
        {
            arr[i] = i * 2;
            printf("Parent process arr[%d] : %d\n", i, arr[i]);
        }
        write(pipefd[1], "X", 1); // Signal child to start
        close(pipefd[1]);
        free(arr);
    }
    return 0;
}
