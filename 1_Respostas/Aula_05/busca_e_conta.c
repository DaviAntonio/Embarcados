#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib_arqs.h"

int main(int argc, char **argv)
{
	FILE *fp;
	char *conteudo = NULL;
	/*
	* Tamanho do arquivo em bytes, quantidade de vezes que o padrão
	* aparece
	*/

	unsigned int tam = 0, qtdp = 0;

	/*
	* ./busca_e_conta	padrao	arquivo	(null)
	* argv[0]		argv[1]	argv[2]	argv[3]
	* Considerando argv[argc]
	*/
	if ((argc < 2) || (argv[2] == NULL)) {
		printf("Uso:\n./busca_e_conta padrao arquivo\n");
		exit(-1);
	}

	tam = tam_arq_texto(argv[2]);

	if (tam <= 0) {
		printf("tam_arq_texto: Erro na leitura do arquivo %s\n", argv[2]);
		exit(-1);
        }

        conteudo = malloc(sizeof(char)*tam + 1);
        le_arq_texto(argv[2], conteudo);

	/* Procurar a substring argv[1] na string conteudo */
	while ((conteudo = strstr(conteudo, argv[1])) != NULL) {
		qtdp++;
		conteudo++;
	}

	printf("'%s' ocorre %d vezes no arquivo '%s'\n", argv[1],
	qtdp, argv[2]);

	free(conteudo);
	conteudo = NULL;

	return 0;
}
