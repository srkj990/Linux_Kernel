#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid = fork(); // Create a new process

    if (pid == 0)
    {
        // Child process
        printf("Child PID: %d\n", getpid());
    }
    else
    {
        // Parent process
        printf("Parent PID: %d, Child PID: %d\n", getpid(), pid);
    }
    return 0;
}