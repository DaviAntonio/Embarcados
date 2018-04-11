#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void le_pipe(int fd);

int main(void)
{
	/* Descritor do pipe */
	int fd[2];

	if (!pipe(fd)) {
		puts("Pipe criado com sucesso");
	} else {
		puts("Erro ao criar pipe");
		exit(-1);
	}

	if (fork()) {
	/* Processo Pai */
		char msg[] = {"Os dois se enganam. É a mente dos senhores que \
se move."};
		sleep(2);
		le_pipe(fd[0]);

		write(fd[1], msg, sizeof(msg));
		sleep(1);

		wait(NULL);
	} else if (fork()) {
	/* Filho 1 */
		char msg[] = {"Quando o vento passa, é a bandeira que se move."};
		write(fd[1], msg, sizeof(msg));
		sleep(2);

		le_pipe(fd[0]);
	} else {
	/* Filho 2 */
		char msg[] = {"Não, é o vento que se move."};
		le_pipe(fd[0]);

		write(fd[1], msg, sizeof(msg));
		sleep(1);
	}
	return 0;
}

void le_pipe(int fd)
{
	char c, *str = NULL;
	int s, i = 0;
	//puts("Inicio de leitura");
	str = (char *) malloc(2*sizeof(char));
	do{
		s = read(fd, &c, 1);
		str[i] = c;
		str = (char *) realloc(str, ++i);
	} while (c != '\0');
	str = (char *) realloc(str, ++i);
	str[i] = '\0';
	//puts("Fim de leitura");
	puts(str);
	//printf("Leitura: %s\n", str);
	free(str);
	str = NULL;
}
