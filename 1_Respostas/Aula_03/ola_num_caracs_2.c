#include <stdio.h>
#include "num_caracs.h"

int main(int argc, char ** argv)
{
        int i, qtdct = 0;
        for(i = 0; i < argc; i++){
                qtdct += Num_Caracs(argv[i]);
	}
                printf("Total de caracteres de entrada: %d\n", qtdct);
        return 0;
}

