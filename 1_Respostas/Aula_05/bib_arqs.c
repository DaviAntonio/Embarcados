#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

//#include <stdio.h>

int tam_arq_texto(char *nome_arquivo)
{
	int fd;
	int tam = 0;

	fd = open(nome_arquivo, O_RDONLY);

	if (fd == -1) {
		return -1;
		close(fd);
	}

	tam = lseek(fd, 0, SEEK_END);

	close(fd);

	if (tam == -1) 
		return -1;

	return tam;
}

void le_arq_texto(char *nome_arquivo, char *conteudo)
{
	int fd;
	unsigned int i = 0;
	char ch, tmp;

	fd = open(nome_arquivo, O_RDONLY);

	if (fd == -1) {
		conteudo[0] = '\0';
		return;
	}

	while (tmp = read(fd, &ch, 1)) {
		if (tmp == -1) {
			conteudo[i] = '\0';
			return;
		}
		conteudo[i++] = ch;
		//printf("i = %d\tch = %c\tvalor = %d\n", i-1, ch, (int) ch);
	}

	conteudo[i] = '\0';
	close(fd);
}
