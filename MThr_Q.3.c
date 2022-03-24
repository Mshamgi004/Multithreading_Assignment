// Multithreading process //
// Change the default properties of POSIX threads //
// Q.3 //
// MAHADEV G I //


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<fcntl.h>


void* operate(void *param)
{
	printf("This is pthread creation using user attributes\n");
	sleep(2);
	
	return NULL;
}

int main(void)
{
	pthread_attr_t atr;
	pthread_t tid;
	
	void *stack;
	size_t size;
	int e;
	
	size_t stksize = 4600;
	
	
	pthread_attr_init(&atr);			 // initializing pthread attribute
	pthread_attr_getstacksize(&atr, &size);	        //  get the size of stack
	pthread_attr_getstackaddr(&atr, &stack);       //   get stack address
	
	printf("default address : %08x  -> default size of stack : %d\n", stack, size);
	
	stack = (void*)malloc(stksize);		       //   define a new stack using malloc function 
	
	pthread_attr_setstack(&atr, stack, stksize);			// set the stack value
	
	pthread_create(&tid, &atr, operate, NULL);        // create a new pthread
	
	
	pthread_attr_getstack(&atr, &stack, &size);			//get info of new stack
	
	printf("\ndefault address : %08x  -> default size of stack : %d\n", stack, size);
	
	return 0;
}