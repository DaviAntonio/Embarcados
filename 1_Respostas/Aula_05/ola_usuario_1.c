#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE *fp;
	unsigned int idade;
	char nomep[128], nomearq[128];
	char ext[] = ".txt";

	printf("Digite o seu nome: ");
	scanf("%s", nomep);

	printf("Digite a sua idade: ");
	scanf("%d", &idade);

	strcpy(nomearq, nomep);
	strcat(nomearq, ext);

	fp = fopen(nomearq, "w");

	if (fp == NULL) {
		printf("Erro ao abrir o arquivo '%s'\n", nomearq);
		exit(-1);
	}

	fprintf(fp, "Nome: %s\n", nomep);
	fprintf(fp, "Idade: %d\n", idade);

	fclose(fp);

	return 0;
}
