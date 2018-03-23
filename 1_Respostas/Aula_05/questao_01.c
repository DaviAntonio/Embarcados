#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>	/* Para a funcao open() */
#include <unistd.h>	/* Para a funcao close() */

int main(void)
{
	int fd;
	char frase[] = "Ola mundo!";

	fd = open("ola_mundo.txt", O_RDWR, O_CREAT);
	
	if(fd = -1){
		puts("Erro ao criar o arquivo\n");
		exit(-1);
	}

	fputs(frase, fp);

	fclose(fp);

	return 0;
}
