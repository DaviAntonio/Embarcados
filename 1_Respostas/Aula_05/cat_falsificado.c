#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#include "bib_arqs.h"

int main(int argc, char **argv)
{
	char *conteudo = NULL;
	unsigned int tam;

	if (argv[1] == NULL)
		printf("Uso:\n./cat_falsificado arquivo\n");

	tam = tam_arq_texto(argv[1]);

	if (tam <= 0) {
		printf("tam_arq_texto: Erro na leitura do arquivo %s\n", argv[1]);
		exit(-1);
	}

	conteudo = malloc(sizeof(char)*tam + 1);
	le_arq_texto(argv[1], conteudo);

	printf("%s\n", conteudo);

	free(conteudo);
	conteudo = NULL;

	return 0;
}
