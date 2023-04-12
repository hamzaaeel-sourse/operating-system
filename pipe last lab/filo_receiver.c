#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(){

    int arr[5];
    int fd = open("hamza", O_RDONLY);  //Opening to read
    for (int i = 0; i < 5; i++)
    {
        if( (read(fd, &arr[i], sizeof(int))) ==  -1){
        printf("Error");
        }
        printf("Recieved value number %d", arr[i]);
    }

    close(fd);
    return 0;

}
