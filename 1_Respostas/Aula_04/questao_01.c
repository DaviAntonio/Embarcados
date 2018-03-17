#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE * fp;
	char frase[] = "Ola mundo!";

	fp = fopen("ola_mundo.txt", "w");
	
	if(fp == NULL){
		puts("Erro ao criar o arquivo\n");
		exit(-1);
	}

	fputs(frase, fp);

	fclose(fp);

	return 0;
}
