#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
        FILE *fp;
        unsigned int idade;
        char nomearq[128];
        char ext[] = ".txt";

	if (argc < 2) {
		printf("Uso: ./ola_usuario_2 nome idade\n");
		exit(-1);
	}

        strcpy(nomearq, argv[1]);
        strcat(nomearq, ext);

	sscanf(argv[2], "%d", &idade);

        fp = fopen(nomearq, "w");

        if (fp == NULL) {
                printf("Erro ao abrir o arquivo '%s'\n", nomearq);
                exit(-2);
        }

        fprintf(fp, "Nome: %s\n", argv[1]);
        fprintf(fp, "Idade: %d\n", idade);

        fclose(fp);
	return 0;
}
