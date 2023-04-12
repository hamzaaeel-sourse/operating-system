#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void* print(void* args)
{
    printf("The arg is = %d\n",*(int*) args);
    pthread_exit(NULL);
}
int main(int argc, char const *argv[])
{
    pthread_t threads[10];
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        int *a = (int*) malloc(sizeof(int));
        *a = i;
        pthread_create(&threads[i],NULL,&print,a);   
    }

    for (i = 0; i < 10; i++)
    {
        pthread_join(threads[i], NULL);
    }
    
    
    
    return 0;
}
