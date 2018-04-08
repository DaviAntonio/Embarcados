/*
* Cria processo filho e um pipe de comunicação.
* Processo pai envia valores 1:1:10 para o filho em 1 Hz
* Depois do pai enviar o número 10, aguarda 1 segundo e termina
* O filho escreve na tela cada numero recebido e ao receber 10 termina
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	/* Descritor do pipe */
	int fd[2];

	/* Criar pipe */
	if (!pipe(fd)) {
		puts("Pipe criado com sucesso!\n");
	} else {
		puts("Erro na criação do pipe!\n");
		exit(-1);
	}

	if (fork()) {
	/* Processo pai */
		int i;
		for (i = 1; i <= 10; i++) {
			write(fd[1], &i, sizeof(int));
			sleep(1);
		}
	} else {
	/* Processo filho */
		/* 
		* Lembrando que o processo filho não tem acesso aos dados do pai
		*/
		int i = 0;
		while (i != 10) {
			read(fd[0], &i, sizeof(int));
			printf("%d\n", i);
		}
		
	}
	return 0;
}
