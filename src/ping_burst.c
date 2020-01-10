#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NB_THREADS 10000

// needs to be root for -i
void *ping(void *arg)
{
	system("ping -i 0 192.168.0.2");
	pthread_exit(0);
}

int main(void)
{
	pthread_t ping_threads[NB_THREADS];

	for (int i = 0; i < NB_THREADS; i++) {
		pthread_create(&ping_threads[i], NULL, ping, NULL);
	}

	printf("the main thread continues with its execution\n");

	for (int i = 0; i < NB_THREADS; i++) {
		pthread_join(ping_threads[i], NULL);
	}

	printf("ping finished");

	scanf;

	return EXIT_SUCCESS;
}