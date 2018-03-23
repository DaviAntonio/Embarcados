#include <stdio.h>

int tam_arq_texto(char *nome_arquivo)
{
	FILE *fp;
	int tam = 0;

	fp = fopen(nome_arquivo, "r");

	if (fp == NULL)
		return -1;

	while (fgetc(fp) != EOF)
		tam++;

	return tam;
}

void le_arq_texto(char *nome_arquivo, char *conteudo)
{
	FILE *fp;
	unsigned int i = 0;
	int ch;

	fp = fopen(nome_arquivo, "r");

	if (fp == NULL) {
		conteudo[0] = '\0';
		return;
	}

	while ((ch = fgetc(fp)) != EOF)
		conteudo[i++] = ch;

	conteudo[i] = '\0';
	fclose(fp);
}
