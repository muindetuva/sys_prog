#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *customThreadFunction()
{
    for (int i = 0; i < 15; i++)
    {
        printf("I am a custom thread function created by the programmer.\n");
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t thread; // Thread descriptot

    int status; // To store the status of the thread

    status = pthread_create(&thread, NULL, customThreadFunction, NULL);
    // status = 0 if thread is created succesfully
    // status = 1 if thread is unable to create
    
    if(!status)
    {
        printf("Custom thread created succesfully\n");
    } else {
        printf("Unable to create custom thread\n");
        return 0;
    }

    // Main function for loop
    for (int i = 0; i < 15; i++)
    {
        printf("I am the process thread created by compiler by default\n");
        sleep(1);
    }
    return 0;
}
