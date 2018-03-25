#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fd, i = 0;
	unsigned int idade;
	char nomep[128], nomearq[128];
	char ext[] = ".txt";
	char prnome[] = "Nome: ";
	char pridade[] = "Idade: ";
	char jmp = '\n';
	char widade[16];

	printf("Digite o seu nome: ");
	scanf("%s", nomep);

	printf("Digite a sua idade: ");
	scanf("%d", &idade);

	sprintf(widade, "%d anos", idade);

	strcpy(nomearq, nomep);
	strcat(nomearq, ext);

	fd = open(nomearq, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

	if (fd == -1) {
		printf("Erro ao abrir o arquivo '%s'\n", nomearq);
		exit(-1);
	}

	while (prnome[i] != '\0')
		write(fd, &prnome[i++], 1);

	for (i = 0; nomep[i]; i++)
		write(fd, &nomep[i], 1);

	for(i = 0, write(fd, &jmp, 1); pridade[i]; i++)
		write(fd, &pridade[i], 1);

	for(i = 0; widade[i]; i++)
		write(fd, &widade[i], 1);

	write(fd, &jmp, 1);

	close(fd);

	return 0;
}
