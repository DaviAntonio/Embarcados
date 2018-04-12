#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void le_pipe(int fd);

int main(void)
{
	int fd[2];

	if (!pipe(fd)) {
		puts("Pipe criado com sucesso");
	} else {
		puts("Falha ao criar pipe");
		exit(-1);
	}

	if (fork()) {
	/* Processo pai */
		le_pipe(fd[0]);
		puts("Pai leu e vai esperar pelo filho");
		wait(NULL);
		puts("Filho encerrou, terminar");
	} else {
	/* Processo filho */
		char user[34];
		int tam = 0;
		/* man useradd informa que username deve ter até 32 caracteres */
		puts("Digite nome de usuário");
		fgets(user, 34*sizeof(char), stdin);
		if (user == NULL) {
			puts("Erro ao ler stdin");
			exit(-1);
		}

		//puts("Arrumar string");

		/* Se encontrar um \n trocar por \0 */
		tam = strcspn(user, "\n");
		user[tam] = '\0';

		//puts("Filho irá escrever");
		/* Passar nome do usuario pelo pipe */
		write(fd[1], user, tam*sizeof(char) + 1);
		//printf("Filho acabou de escrever %s", user);
	}

	return 0;
}

void le_pipe(int fd)
{
	char c, *str = NULL;
	int i = 0;
	//puts("Inicio de leitura");
	str = (char *) malloc(2*sizeof(char));
	do{
		read(fd, &c, 1);
		//printf("Lido %c\n", c);
		str[i] = c;
		str = (char *) realloc(str, ++i);
	} while ((c != '\0') && (i <= 34));
	str = (char *) realloc(str, ++i);
	str[i] = '\0';
	//puts("Fim de leitura");
	puts(str);
	//printf("Leitura: %s\n", str);
	free(str);
	str = NULL;
}
