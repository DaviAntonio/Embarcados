1. Quais são as vantagens e desvantagens em utilizar:

(a) fork?  
Um fork cria um novo processo. Cada processo filho possui o próprio espaço de
memória protegido, mas como consequência disso a comunicação torna-se um pouco
mais difícil, dependendo de mecanismos como sinais e pipes. A criação de um
processo filho também é custosa computacionalmente já que todas as variáveis e
funções do processo pai são copiadas para o processo filho.

(b) threads?  
As thread compartilham a memória entre si, o que facilita a comunicação entre
elas e diminui o custo da troca de contexto, mas gera problemas de corrupção de
 dados.

2. Quantas threads serão criadas após as linhas de código a seguir? Quantas coexistirão? Por quê?

(a)

```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```  
Há três threads, a principal `main`, `t1` e `t2`. As três coexistem até o fim, 
pois foram juntadas.

(b)
```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_join(t1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```  
Há três threads, a principal `main`, `t1` e `t2`. As três terminam juntas, mas 
`t2` inicia um pouco após a criação de `t1`.

3. Apresente as características e utilidades das seguintes funções:

(a) `pthread_setcancelstate()`  
`int pthread_setcancelstate(int state, int *oldstate);`  
Configura o estado do cancelamento para a thread que chama. O estado antigo do 
cancelamento é retornado na variável `oldstate`. O argumento `state` pode ser:  
* PTHREAD_CANCEL_ENABLE. O padrão em todas novas threaads. Determina que a 
thread responderá a um pedido de cancelamento.
* PTHREAD_CANCEL_DISABLE. A thread não pode ser cancelada. Pedidos de 
cancelamento são bloqueados até que a thread torne-se cancelável.

(b) `pthread_setcanceltype()`  
`int pthread_setcanceltype(int type, int *oldtype);`  
Configura o tipo do pedido de cancelamento para a thread que a chama. O tipo
anterior é retornado em `oldtype`. O valor de `type` pode ser:  
* PTHREAD_CANCEL_DEFERRED. O padrão. Um pedido de cancelamento é travado até que
 a thread chame uma função que é um ponto de cancelamento.
* PTHREAD_CANCEL_ASYNCHRONOUS. A thread pode ser cancelada a qualquer momento.
Normalmente será cancelada assim que receber um pedido de cancelamento, mas o 
sistema não garante isso.
(DICA: elas são relacionadas à função pthread_cancel().)
