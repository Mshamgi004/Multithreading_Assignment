// Multithreading process //
// Multiple process running same time //
// Q.1 //
// MAHADEV G I //

#include<stdio.h>
#include<stdlib.h>

int sharedvar=5;

void *thread_inc(void *arg)
{
     sharedvar++;                           // Operation 1 increament
     printf("after incr=%d\n",sharedvar);   
}

void *thread_dec(void *arg)
{
     sharedvar--;                           // Operation 2 decreament
     printf("after decr=%d\n",sharedvar);
}   

int main()
{
     pthread_t thread1, thread2;             
     
     pthread_create(&thread1, NULL, thread_inc, NULL);   // Pthread creation 1
     pthread_create(&thread2, NULL, thread_dec, NULL);   // Pthread creation 2
     
     pthread_join(thread1, NULL);         // Joining pthread 1
     pthread_join(thread2, NULL);         // Joining pthread 2
     
     printf("sharedvar =%d\n",sharedvar);
     
     return 0;
}     