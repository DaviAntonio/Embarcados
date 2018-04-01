#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	int i;
	char * lista[] = {" ", NULL};
	for (i = 1; i < argc; i++)
		if (!fork()) {
			//lista[0] = argv[i];
			execvp(argv[i], lista);
			printf("Erro\n");
		}
	return 0;
}
