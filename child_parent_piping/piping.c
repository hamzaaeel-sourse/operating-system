#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char const *argv[])
{
    int fd[2];
    int pipe_code = pipe(fd);
    if (pipe_code == -1)
    {
        printf("EEROR");
    }

    if (fork() == 0)
    {
        int a;
        printf("Enter Number you want to send to parent");
        scanf("%d", &a);
        close(fd[0]);
        write(fd[1], &a, sizeof(int) );
        close(fd[1]);
    }

    else
    {
        close(fd[1]);
        int b = 0;
        read(fd[0],&b,sizeof(int));
        close(fd[0]);
        printf("RECEIVED FROM THE CHILD USING PIPE %d\n",b);
        wait(NULL);   
    }
    return 0;
}
