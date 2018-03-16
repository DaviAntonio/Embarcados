#include <stdio.h>

int main(void)
{
	char nome[128];
	printf("Digite seu nome:\n");
	scanf("%s", nome);
	printf("Ola %s\n", nome);
}
