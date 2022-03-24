// Multithreading Process //
// Mutex:Threads Synchronization //
// Q.5 //
// MAHADEV G I //


#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>

int sharedVar = 5;

pthread_mutex_t my_mutex;    

void *thread_inc(void *arg)
{
     pthread_mutex_lock(&my_mutex); // Mutex locking 
     sharedVar++;
     pthread_mutex_unlock(&my_mutex); // Mutex unlocking
}

void *thread_dec(void *arg)
{
     pthread_mutex_lock(&my_mutex);   // Mutex locking 
     sharedVar--;
     pthread_mutex_unlock(&my_mutex);  // Mutex unlocking

}

int main()
{
     pthread_t thread1, thread2;   // declaring two new threads ( thread 1 and thread 2)
   
     pthread_mutex_init(&my_mutex,NULL);  // mutex initializing 
   
     pthread_create(&thread1, NULL , thread_inc, NULL);  //creating pthread1
     pthread_create(&thread2, NULL , thread_dec, NULL);  // creating pthread2  
   
     pthread_join(thread1, NULL);  // pthread join 1
     pthread_join(thread2, NULL);  // pthread join 2
   
     printf("sharedVar = %d \n", sharedVar);
   
     return 0;
   
}     