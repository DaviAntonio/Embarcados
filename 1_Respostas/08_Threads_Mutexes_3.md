1. Apresente as características e utilidades das seguintes funções:

(a) `popen()`  
```
#include <stdio.h>
FILE *popen(const char *command, const char *type);
```  
Essa função cria um pipe para um novo processo. Ao contrários dos pipes criados 
pela `pipe()`, estes são unidirecionais. A própria função cria um pipe, faz o
fork e invoca o shell. Escrever na stream criada é escrever na stdin do novo 
programa, e ler dela é ler a stdout.

(b) `pclose()`  
```
#include <stdio.h>
int pclose(FILE *stream);
```  
Fecha uma stream criada pela função `popen()`.

(c) `fileno()`  
```
#include <stdio.h>
int fileno(FILE *stream);
```
Examina a stream passada como argumento e retorna seu descritor de arquivo como 
inteiro.

2. Quais são as vantagens e desvantagens em utilizar:

(a) `popen()?`  
É possível escrever diretamente na entrada do programa lançado. O pipe não é 
bidirecional e a função possui overhead.

(b) `exec()?`  
Há substituição de todo o ambiente do processo que chamou a função. A 
comunicação é bem mais difícil, pois os processos não possuem pipes que 
conheçam e provavelmente será feita por sinais ou arquivos externos ou pelos 
próprios argumentos passados para o novo processo.