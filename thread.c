#include<stdio.h>
#include <pthread.h>
#include <stdlib.h>
void* add(void* num)
{
    int arg = *(int*)num;

    int *a = (int*) malloc(sizeof(int));
    *a = arg + 1;
    pthread_exit((void*) a);
    
}
int main(int argc, char const *argv[])
{
    int arg = 4;
    int *a;
    pthread_t thread_id;
    
    pthread_create(&thread_id,NULL,&add,&arg); //passing args to the thread
    pthread_join(thread_id, (void **) &a); //joining the thread and getting return

    printf("The resultant = %d\n",*a);

    return 0;
}
