#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <sys/types.h>
void handler (void *ptr);

sem_t mutex;
int counter;

int main()
{
	int i[2];
	pthread_t thread_a;
	pthread_t thread_b;

	i[0]=0;
	i[1]=1;

	sem_open(&mutex, 0, 1);

	pthread_create(&thread_a, NULL, (void *) &handler, (void*) &i[0]); 
       pthread_create(&thread_b, NULL, (void *) &handler, (void*) &i[1]);  	

       sem_close(&mutex);

       exit(0);
}


void handler(void *ptr)
{
	int x;
	x = *((int *) ptr);

	printf("thread %d waiting to enter critical region .. \n",x);
	sem_wait(&mutex);

	printf("Thread %d: Now in critical region...\n", x);

	printf("Thread %d: Counter Value: %d\n", x, counter);

	printf("Thread %d: Incrementing Counter...\n", x);


	counter++;

	printf("Thread %d: New Counter Value: %d\n", x, counter);

	printf("Thread %d: Exiting critical region...\n", x);

	sem_post(&mutex);
	pthread_exit(0);
}


