1. Considerando a biblioteca-padrão da linguagem C, responda:

(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?  
```C
#include <stdio.h>
FILE *fp = fopen(char *caminho, char *modo);
```

(b) Quais são as funções (e seus protótipos) para escrever em arquivos?  
```C
#include <stdio.h>
int fprintf(FILE *fp, const char *formato, ...);
int fputc(int c, FILE *fp);
int fputs(const char *s, FILE *fp);
size_t fwrite(const void *ptr, int nbytes, int qtd, FILE *fp);
```

(c) Quais são as funções (e seus protótipos) para ler arquivos?  
```C
#include <stdio.h>
int fscanf ( FILE *fp, char *formato, ... );
```

(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?

(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?

2. O que é a norma POSIX?

3. Considerando a norma POSIX, responda:

(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?

(b) Quais são as funções (e seus protótipos) para escrever em arquivos?

(c) Quais são as funções (e seus protótipos) para ler arquivos?

(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?

(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?
