// Multithreading Process //
// Display thread id and also print calling process pid //
// Q.4 //
// MAHADEV G I //

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/types.h>

pthread_t tid;

void* operate(void *arg)
{
	printf("\nNewly created thread in execution\n");
	printf("pthread id : %lu\nCalling Process id : %d\n", pthread_self(), getpid());
	
	return NULL;
}


int main(void)
{
	int re;
	
	re = pthread_create(&tid, NULL, operate, NULL);			// thread creation process using pthread create
	
	if(re)
	{
		printf("Not created\n");
	}
	
	else
	{
		printf("thread is created\n");
		
	}
	
	pthread_join(tid, NULL);                                      // pthread is joined 
	
	printf("\nExit from main process\n");
	
	return 0;
}