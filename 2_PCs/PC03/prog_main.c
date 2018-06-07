#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prog_defs.h"
#include "prog_functions.h"

int main(void)
{
	char c;

	puts("Favor iniciar a câmera no CHDK e conectá-la à uma das portas USB da \
Raspberry Pi");
	puts("Favor posicionar a câmera alinhada com a página desejada e com a \
objetiva voltada para cima");
	//puts("Pressione ENTER quando pronto");
	//scanf("%c", &c);
	//Ler botão se quer continuar
	read_continue(21);

	/* Inicializar chdk, câmera deve estar preparada */
	init_camera();

	puts("A foto será capturada");
	read_continue(21);

	/* Tirar foto e corrigir orientação */
	take_photo();

	/* Chamar o tesseract */
	reco_char();

	/* Chamar o espeak */
	speak();

	/* Disconectar a câmera */
	dc_camera();

	return 0;
}
