#include <stdio.h>
#include "num_caracs.h"

int main(int argc, char ** argv)
{
        int i, qtdc;
        for(i = 0; i < argc; i++){
		qtdc = Num_Caracs(argv[i]);
                printf("Argumento: %s/ Numero de caracteres %d\n", argv[i],
		 qtdc);
	}
	return 0;
}
