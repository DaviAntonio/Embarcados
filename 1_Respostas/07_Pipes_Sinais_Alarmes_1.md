1. Quantos pipes serão criados após as linhas de código a seguir? Por quê?

(a)
```C
int pid;
int fd[2];
pipe(fd);
pid = fork();
```  
Um único pipe. Pai e filho possuem o mesmo pipe apesar de serem processos
diferentes.

(b)
```C
int pid;
int fd[2];
pid = fork();
pipe(fd);
```  
Dois pipes diferentes. Cada processo criou um pipe.

2. Apresente mais cinco sinais importantes do ambiente Unix, além do `SIGSEGV`, `SIGUSR1`, `SIGUSR2`, `SIGALRM` e `SIGINT`. Quais são suas características e utilidades?  
`SIGQUIT` é emitido aos processos do terminal quando a tecla de abandono
(QUIT ou a combinação Control+D) é acionada.
`SIGKILL` mata o processo imediatamente e não pode ser ignorado ou interceptado.
`SIGTERM` indica para o software que este deva terminar de forma normal.
`SIGHUP` indica uma desconexão do terminal ao processo.
`SIGFPE` indica um erro de cálculo em ponto flutuante gerado por erro de
programação.

3. Considere o código a seguir:

```C
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void tratamento_alarme(int sig)
{
	system("date");
	alarm(1);
}

int main()
{
	signal(SIGALRM, tratamento_alarme);
	alarm(1);
	printf("Aperte CTRL+C para acabar:\n");
	while(1);
	return 0;
}
```

Sabendo que a função `alarm()` tem como entrada a quantidade de segundos para terminar a contagem, quão precisos são os alarmes criados neste código? De onde vem a imprecisão? Este é um método confiável para desenvolver aplicações em tempo real?  
A precisão da contagem é da ordem de algumas dezenas de milissegundos.
Esta imprecisão vem do grande número de procesos que o kernel executa ao mesmo
tempo, fazendo com que os processos tenham que compartilhar o tempo de execução
do processador.
A imprecisão variável torna este método não confiável para aplicações em tempo real.