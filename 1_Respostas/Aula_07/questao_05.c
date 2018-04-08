#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void func_ctrl_c();
void func_ps();

int main(void)
{
	signal(SIGINT, func_ctrl_c);
	signal(SIGALRM, func_ps);
	alarm(1);
	while (1);
	return 0;
}

void func_ctrl_c()
{
	puts("Processo terminado");
	exit(0);
}

void func_ps()
{
	if (!fork())
		execlp("ps", "-e", "--sort=-pcpu", (char *)NULL);
	else
		alarm(1);
}
