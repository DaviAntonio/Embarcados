#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	printf("Processo pai com PID - %d\n", getpid());
	printf("Novo filho\n");

	if (fork()) {
		if (fork()) {
			printf("Novo filho\n");
		} else {
			printf("Filho 02 com PID - %d\n", getpid());
			}
	} else {
		printf("Filho 01 com PID - %d\n", getpid());
	}

	return 0;
}
