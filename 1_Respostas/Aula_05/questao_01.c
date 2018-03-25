#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>	/* Para a funcao open() */
#include <unistd.h>	/* Para a funcao close() */

int main(void)
{
	int fd, i = 0;
	char frase[] = "Ola mundo!";

	/*
	* Abrir arquivo para leitura e escrita. Criar se não existir.
	* Criar com permissões para o usuário ler e escrever.
	*/
	fd = open("ola_mundo.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	
	if(fd == -1){
		puts("Erro ao criar o arquivo\n");
		exit(-1);
	}

	while(frase[i] != '\0')
		write(fd, &frase[i++], 1);
	
	close(fd);

	return 0;
}
