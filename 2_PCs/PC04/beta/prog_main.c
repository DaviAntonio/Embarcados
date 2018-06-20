#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include "prog_defs.h"
#include "prog_functions.h"

//Pinos GPIO
#define PHOTO 15
#define LIGA 14
#define PLAY 17
//#define RETURN 04;
//#define PAUSE 05;


pthread_t foto_id, liga_id, play_id;

struct pino_e_var{
	int pino;
	int variavel;
};

void ctrl_c()
{
	pthread_cancel(foto_id);
	pthread_cancel(liga_id);
	pthread_cancel(play_id);

	read_continue(PHOTO, 3);
	read_continue(LIGA, 3);
	read_continue(PLAY, 3);

	exit(0);
}

void* ativa_pino(void* pino_desejado){
	struct pino_e_var* p = (struct pino_e_var*) pino_desejado;
	
	//printf("Pino %d ativado\n",p->pino);
	while(1){
		read_continue(p->pino, 2);
		p->variavel = 1;
		printf("laço %d : valor %d\n", p->pino, p->variavel);
		sleep(5);
	}
}

int main(void)
{
	signal(SIGINT, ctrl_c);
	char c;

	struct pino_e_var ligar, continuar, tirar_foto;

	int estado_atual=1,	proximo_estado=1;

	

	puts("Favor iniciar a câmera no CHDK e conectá-la à uma das portas USB da \
Raspberry Pi");
	puts("Favor posicionar a câmera alinhada com a página desejada e com a \
objetiva voltada para cima");
	//puts("Pressione ENTER quando pronto");
	//scanf("%c", &c);
	//Ler botão se quer continuar
	//read_continue(21);

	while(1){

		switch(estado_atual){
			case 1: //Inicialização
			
				/*Configurando o botão de ligar*/
				ligar.pino = LIGA;
				ligar.variavel = 0;
				printf("Ligar.pino = %d\n, Ligar.variavel = %d\n", ligar.pino,
ligar.variavel);
				read_continue(ligar.pino, 1);
				pthread_create(&liga_id, NULL, &ativa_pino, &ligar);

				/*Configurando o botão de continuar*/
				continuar.pino = PLAY;
				continuar.variavel = 0;
				read_continue(PLAY, 1);
				pthread_create(&play_id, NULL, &ativa_pino, &continuar);

				/*Configurando o botão de pausar*/
				//pausar.pino = PAUSE;
				//pausar.variavel = 0;
				//pthread_create(&foto_id, NULL, &ativa_pino, &pausar);

				/*Configurando o botão de pausar*/
				tirar_foto.pino = PHOTO;
				tirar_foto.variavel = 0;
				read_continue(PHOTO, 1);
				pthread_create(&foto_id, NULL, &ativa_pino, &tirar_foto);
				while (ligar.variavel != 1);
				printf("Conseguiu sair do while: ligar = %d\n", ligar.variavel);
				proximo_estado = 2; 
				break;
				
			case 2: //Inicialização da camera
			
				/* Inicializar chdk, câmera deve estar preparada */
				init_camera();
				proximo_estado = 3;
				break;
				
			case 3:	//Tira foto do documento
			
				/* Tirar foto e corrigir orientação */
				while(tirar_foto.variavel != 1)
				take_photo();
				proximo_estado = 4;
				break;
				
			case 4: //Converter imagem em texto
			
				/* Chamar o tesseract */
				reco_char();
				proximo_estado = 5;
				break;
				
			case 5: //Divide em pedaços
			
				/*Dividir o arquivo texto*/
				//divide_text();
				proximo_estado = 6;
				break;
				
			case 6: //Escolha das opções

				if(ligar.variavel == 0){//Desligar
					ligar.variavel = 1;
					proximo_estado = 11;
				}else if(continuar.variavel == 1){//Vai para o play
					continuar.variavel = 0;
					proximo_estado = 7;
				}else if(tirar_foto.variavel == 1){//Tira outra foto
					tirar_foto.variavel = 0;
					proximo_estado = 3;
				}else{
					proximo_estado = 6;
				}

				break;
				
			case 7://PLAY
			
				/* Chamar o espeak */
				speak();
				proximo_estado = 6;

				proximo_estado = 6;
				break;
			case 8:
				proximo_estado = 6;
				break;
			case 9:
				proximo_estado = 6;
				break;
			case 10:
				proximo_estado = 6;
				break;
				
			case 11: //Deligar o sistema
			
				/* Disconectar a câmera */
				dc_camera();
				if(ligar.variavel == 0){
					proximo_estado = 11;
				}else{
					proximo_estado = 2;
				}
				break;
		}
		printf("Estado: %d\n", estado_atual);
		estado_atual = proximo_estado;
		sleep(5);
	}

	return 0;
}
