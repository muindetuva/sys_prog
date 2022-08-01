#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *customThreadFunction()
{
    for (int i = 1; i <= 5; i++)
    {
        printf("I am a custom thread created by programmer\n");
        sleep(1);
        if (i == 3)
        {
            printf("My JOB is done. I am now being terminated by programmer\n");
            pthread_exit(NULL);
        }
    }
    
    return 0;
}

int main()
{
    pthread_t thread; // Thread descriptor
    
    pthread_create(&thread, NULL, customThreadFunction, NULL);


    for (int i = 0; i < 5; i++)
    {
        printf("I am the process created by compiler by default\n");
        sleep(1);
    }

    return 0;
}
