#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t lock;
void *mythread_fun(void *vargp)
{
	sleep(1);
	pthread_mutex_lock(&lock);
	
	counter++;

	printf("printing the thread %d start\n", counter);
	for(int i ; i<23452354; i++);
	printf("printing the end of %d thread\n", counter);

	pthread_mutex_unlock(&lock);
	return NULL;

}	

int main()
{
	int i=0;
	pthread_t tid[2];
	printf("before starting the thread\n");
	pthread_mutex_init(&lock, NULL);	
	while (i < 2) {
		pthread_create(&tid[i], NULL, mythread_fun, NULL);
		i++;
	}

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	printf("After thread\n");
}
