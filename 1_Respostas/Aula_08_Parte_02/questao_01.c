#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *printint(void *i)
{
	int *num = (int *) i;
	if (*num < 10) {
		printf("%d\n", *num);
	} else {
		printf("%d\n", *num);
		pthread_exit(NULL);
	}
	return NULL;
}

int main(void)
{
	int i;
	pthread_t thread_01;

	for (i = 1; i <= 10; i++) {
		pthread_create(&thread_01, NULL, &printint, &i);
		sleep(1);
	}
}
