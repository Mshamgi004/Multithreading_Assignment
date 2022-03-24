// Multithreading Assignment //
// Pthread cancel() implementation //
// Q.2 //
// MAHADEV G I //

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* value(void* ptr)
{
    printf("I am learning Threads");
    
    pthread_cancel(pthread_self());     //to exit the current thread
    
    return NULL;	
}

int main()
{
    pthread_t thread;  // NULL value at beginning
    
    pthread_create(&thread, NULL, value, NULL);  // value is a function name
    
    pthread_join(thread, NULL); // Joining the threads 
    
    return 0;
}         