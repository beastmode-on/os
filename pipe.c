#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    int fd[2], n;
    char buffer[100];
    pid_t p;

    pipe(fd);
    p = fork();

    if (p > 0)   // Parent
    {
        close(fd[0]);   // close read end
        printf("Parent passing value to child\n");
        write(fd[1], "hello\n", 6);
        close(fd[1]);   // close write end
        wait(NULL);
    }
    else        // Child
    {
        close(fd[1]);   // close write end
        printf("Child printing received value\n");
        n = read(fd[0], buffer, sizeof(buffer));
        write(1, buffer, n);  // stdout
        close(fd[0]);
    }
    return 0;
}
