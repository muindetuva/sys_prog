#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


void *sayGreetings(void *input) 
{
    printf("Hello ,%s\n", (char *)input);
    pthread_exit(NULL);
}

int main()
{
    char name[50];

    printf("Enter your name: ");
    fgets(name, 50, stdin);


    pthread_t thread;

    pthread_create(&thread, NULL, sayGreetings, name);

    pthread_join(thread, NULL);

    return 0;
}
