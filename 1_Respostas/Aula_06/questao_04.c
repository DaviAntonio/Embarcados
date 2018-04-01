#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int v_global = 0; // Variavel global para este exemplo
void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}

int main(void)
{
	if (!fork()) {
	/* Filho 01 */
	Incrementa_Variavel_Global(getpid());
		if (!fork()) {
		/* Filho 02 */
		Incrementa_Variavel_Global(getpid());
			if (!fork()) {
			/* Filho 03 */
			Incrementa_Variavel_Global(getpid());
			}
		}
	}

	wait(NULL);
	return 0;
}
