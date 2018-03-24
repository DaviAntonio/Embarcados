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
size_t fwrite(const void *ptr, size_t nbytes, size_t qtd, FILE *fp);
```

(c) Quais são as funções (e seus protótipos) para ler arquivos?  
```C
#include <stdio.h>
int fscanf ( FILE *fp, char *formato, ... );
size_t fread(void *ptr, size_t nbytes, size_t qtd, FILE *fp);
int fgetc(FILE *fp);
int getc(FILE *fp;
char *fgets(char *s, int nbytes, FILE *fp);
```

(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?  
```C
#include <stdio.h>
int fseek (FILE *fp, long int offset, int origin);
void rewind (FILE *fp);
int fsetpos(FILE *fp, const fpos_t *pos);
```

(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?  
A biblioteca a ser inclusa para se usar as funções acima é a `stdio.h`.

2. O que é a norma POSIX?  
POSIX (Interface Portátil para Sistemas Operacionais) é uma família de padrões
especificados pelo IEEE para manter a compabtibilidade entre sistemas
operacionais. Nas normas são definidos vários aspectos como interface para
programação de aplicaçoes (API), *shells* de linha de comando e utilitários
de modo a manter a compatibilidade entre as variantes do Unix e outros sistemas.

3. Considerando a norma POSIX, responda:

(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?  
```C
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int open(const char *pathname, int flags, mode_t mode);
```

(b) Quais são as funções (e seus protótipos) para escrever em arquivos?  
```C
#include <unistd.h>
ssize_t write(int fd, const void *buf, size_t count);
```

(c) Quais são as funções (e seus protótipos) para ler arquivos?  
```C
#include <unistd.h>
ssize_t read(int fd, void *buf, size_t count);
```

(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?  
```C
#include <sys/types.h>
#include <unistd.h>
off_t lseek(int fd, off_t offset, int whence);
```

(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?  
As bibliotecas que devem ser incluídas para a utilização das funçoes supracitadas
são *sys/types.h*, *sys/stat.h*, *fcntl.h* e *unistd.h*.