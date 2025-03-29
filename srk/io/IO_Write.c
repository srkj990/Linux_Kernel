#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/wait.h>
#include <semaphore.h>

int main() 
{
    int fd = open("example.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);

    write(fd, "Hello, OS!", 10);
    write(fd, "\nHello", 6);
    if (fd == -1) 
    {
        perror("Failed to open file");
        return 1;
    }
    else
    {
        perror("opened file");
    }
    
    close(fd);
    
    return 0;
}
