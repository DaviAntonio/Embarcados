/*
* Conversa entre processo pai e filho usando pipe
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
	return;
}



int main(void)
{
	/* Descritor do pipe */
	int fd[2];

	/* Criar os pipes */
	if (!pipe(fd)) {
		puts("Pipe criado com sucesso\n");
	} else {
		puts("Falha na criação do pipe\n");
		exit(-1);
	}

	if (fork()) {
	/* Processo pai */
		char msg0[] = {"Não façais nada violento, praticai somente \
aquilo que é justo e equilibrado."};
		char msg1[] = {"Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu..."};
		/* Tempo para filho escrever */
		//puts("0 - Pai vai ler");
		le_pipe(fd[0]);

		//puts("1 - Pai vai escrever");
		write(fd[1], msg0, sizeof(msg0));
		//puts("Pai terminou de escrever");
		/* Tempo para filho ler */
		sleep(1);
		
		//puts("2 - Pai vai ler");
		le_pipe(fd[0]);

		//puts("3 - Pai vai escrever");
		write(fd[1], msg1, sizeof(msg1));
		/* Tempo para filho ler */
		sleep(1);
		
		wait(NULL);
	} else {
	/* Processo filho */
		char msg0[] = {"Pai, qual é a verdadeira essência da sabedoria?"};
		char msg1[] = {"Mas até uma criança de três anos sabe disso!"};
		sleep(1);
		//puts("0 - Filho vai escrever");
		write(fd[1], msg0, sizeof(msg0));
		//puts("Filho terminou de escrever");
		/* Tempo para pai ler */
		sleep(1);
		
		//puts("1 - Filho vai ler");
		le_pipe(fd[0]);

		//puts("2 - Filho vai escrever");
		write(fd[1], msg1, sizeof(msg1));
		/* Tempo para pai ler */
		sleep(1);
		//puts("3 - Filho vai ler");
		le_pipe(fd[0]);
	}

	return 0;
}
