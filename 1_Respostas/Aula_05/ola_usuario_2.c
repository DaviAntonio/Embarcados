#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd;
	char nomearq[128];
	char ext[] = ".txt";
	char prnome[128] = "Nome: ";
	char pridade[128] = "Idade: ";
	char jmp = '\n';

	if (argc < 2) {
		printf("Uso: ./ola_usuario_2 nome idade\n");
		exit(-1);
	}

	strcpy(nomearq, argv[1]);
	strcat(nomearq, ext);

	strcat(prnome, argv[1]);
	strcat(pridade, argv[2]);

	fd = open(nomearq, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

        if (fd == -1) {
		printf("Erro ao abrir o arquivo '%s'\n", nomearq);
		exit(-2);
        }

	write(fd, prnome, strlen(prnome));
	write(fd, &jmp, 1);
	write(fd, pridade, strlen(pridade));
	write(fd, &jmp, 1);

        close(fd);

	return 0;
}
