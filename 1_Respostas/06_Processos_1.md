1. Como se utiliza o comando `ps` para:

(a) Mostrar todos os processos rodando na máquina?  
`ps -e` ou `ps -A`

(b) Mostrar os processos de um usuário?  
`ps -u usuario` ou `ps --user usuario` ou `ps -U usuario`

(c) Ordenar todos os processos de acordo com o uso da CPU?  
`ps -e --sort=pcpu` para listar todos em ordem crescente de uso. Para ordem
decrescente, `ps -e --sort=-pcpu`.

(d) Mostrar a quanto tempo cada processo está rodando?  
A opção `--sort=cputime`, quando incluída, mostra o tempo em ordem crescente.

2. De onde vem o nome `fork()`?  
O nome `fork()` vem do inglês e no contexto da criação de desvios significa
desvio, representando a estrutura em árvore da criação de processos.

3. Quais são as vantagens e desvantagens em utilizar:

(a) `system()`?  
A função `system()` da `stdlib.h` é fácil de ser utilizada, mas bloqueia a
execução do programa e apresenta problemas de segurança.

(b) `fork()` e `exec()`?  
O uso de `fork()` e `exec()` é muito mais complexo e exige a escolha certa da
função da família `exec()` caso os processos a serem lançados precisem de
argumentos.

4. É possível utilizar o `exec()` sem executar o `fork()` antes?  
Sim. O programa em execução (processo) será substituído pelo código chamado pelo
`exec()` e não retornará nada ao término da execução a não ser em caso de erro.

5. Quais são as características básicas das seguintes funções:

(a) `execp()`?  
http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/unistd.h.html

(b) `execv()`?  
```C
int execv(const char *path, char *const argv[]);
```
A lista de argumentos é passada como um vetor de ponteiros.

(c) `exece()`?  
http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/unistd.h.html

(d) `execvp()`?  
```C
int execvp(const char *file, char *const argv[]);
```  
Recebe argumentos como vetor de ponteiros e aceita caminhos relativos, pois
procura no PATH.

(e) `execve()`?  
```C
int execve(const char *filename, char *const argv[], char *const envp[]);
```  
Recebe o programa a executar, que pode ser um binário ou um script; o vetor de
argumentos e o vetor de configurações para o ambiente do programa.

(f) `execle()`?  
```C
int execle(const char *path, const char *arg, ..., (char *) NULL,
char * const envp[]);
```  
Recebe o caminho do programa a executar, os argumentos como uma lista e o vetor
para variáveis de ambiente.