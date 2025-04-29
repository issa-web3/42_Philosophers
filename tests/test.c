



#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void    *func(void *ptr)
{
    int x = *(int *)ptr;
    int *result = malloc(4);
    *result = x * x;
    return (result);
}

int main()
{
    pthread_t   my_thread;

    int x;
    x = 3;


    pthread_create(&my_thread, NULL, func, &x);

    int *result;
    pthread_join(my_thread, (void *)(&result));

    printf("%d\n", *result);

}
