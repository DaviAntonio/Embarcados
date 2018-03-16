#include <stdio.h>

int main(void)
{
	char nome[128];
	printf("Digite seu nome: ");
	scanf("%s", nome);
	printf("Ola %s\n", nome);
}
