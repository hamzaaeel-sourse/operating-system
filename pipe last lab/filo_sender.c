#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
int main(){

    int arr[5];
    printf("Enter the Numbers you want to send through pipe");
    int fd = open("hamza",O_WRONLY);
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
        if (write(fd, &arr[i], sizeof(int)) == -1) 
        {
            printf("error!");
        };
    }

    close(fd);
    return 0;

}
