#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char pic_name[64];
	char tess_lang[8];
	char espk_lang[32];
	char take_photo[256];
	char reco_char[256];
	char spk_cmd[256];

	puts("Digite nome da imagem incluindo extensão");
	scanf("%s", pic_name);

	puts("Digite linguagem do tesseract");
	scanf("%s", tess_lang);

	puts("Digite linguagem do espeak");
	scanf("%s", espk_lang);

	sprintf(take_photo, "ffmpeg -f v4l2 -s 640x480 -i /dev/video0 \
-ss 0:0:10 -frames 1 %s", pic_name);
	puts(take_photo);

	sprintf(reco_char, "tesseract %s saida -l %s", pic_name, tess_lang);
	puts(reco_char);

	sprintf(spk_cmd, "espeak-ng -a 200 -s 110 -v %s -f saida.txt", espk_lang);
	puts(spk_cmd);

	//system(take_photo);
	system(reco_char);
	system(spk_cmd);

	return 0;
}
