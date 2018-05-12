#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define VSIZE 50000

struct vect_sk{
	double *v;
	int lim_inf;
	int lim_sup;
	double res;
};

void fill_vector(double *v);
double sum(double *v, int minpos, int maxpos);

void *sum_t(void *seek);

int main(int argc, char **argv)
{
	double v[VSIZE];

	char arg_threads[] = "-t";
	char arg_comp[] = "-c";

	if (argc < 2) {
		puts("Uso:\nquestao_02 -mode");
		puts("-mode:\n-t\tthreads\n-c\tcompleto");
		exit(-1);
	}

	if (VSIZE%4) {
		printf("VSIZE=%d não divisível por 4\n", VSIZE);
		exit(-2);
	}

	if (!strcmp(argv[1], arg_comp)) {
		double vavg;
		fill_vector(v);
		puts("Vetor inicializado");

		//printf("SUM0 = %lf\n", sum(v, 0, 12500));

		vavg = sum(v, 0, VSIZE)/((float) VSIZE);
		printf("A média por uma thread: %lf\n", vavg);
	}
	
	if (!strcmp(argv[1], arg_threads)) {
		/*
		* A média aritmética de uma média aritmética é igual caso os
		* conjuntos tenham o mesmo número de elementos
		*/
		pthread_t t0, t1, t2, t3;
		double vavg_t;
		struct vect_sk s0, s1, s2, s3;
		double tv[4];

		s0.v = s1.v = s2.v = s3.v = v;
		s0.lim_inf = 0;
		s0.lim_sup = s1.lim_inf = VSIZE/4;
		s1.lim_sup = s2.lim_inf = VSIZE/2;
		s2.lim_sup = s3.lim_inf = (3*VSIZE)/4;
		s3.lim_sup = VSIZE;

		fill_vector(v);
		puts("Vetor inicializado");

		pthread_create(&t0, NULL, &sum_t, &s0);
		pthread_join(t0, NULL);

		pthread_create(&t1, NULL, &sum_t, &s1);
		pthread_join(t1, NULL);

		pthread_create(&t2, NULL, &sum_t, &s2);
		pthread_join(t2, NULL);

		pthread_create(&t3, NULL, &sum_t, &s3);
		pthread_join(t3, NULL);

		tv[0] = s0.res;
		tv[1] = s1.res;
		tv[2] = s2.res;
		tv[3] = s3.res;

		//printf("M0 %lf\n", tv[0]);
		//printf("M1 %lf\n", tv[1]);
		//printf("M2 %lf\n", tv[2]);
		//printf("M3 %lf\n", tv[3]);

		vavg_t = sum(tv, 0, 4)/((float) VSIZE);

		printf("Média por 4 threads é: %lf\n", vavg_t);
	}
	return 0;
}


void fill_vector(double *v)
{
	int i;
	/*
	* Garantir que sempre serão gerados os mesmos números na simulação
	*/
	srandom(0);

	for (i = 0; i < VSIZE; i++)
		v[i] = (double) random();
}

double sum(double *v, int minpos, int maxpos)
{
	/*
	* Os números do vetor são sempre positivos
	*/
	double sum = 0;
	int i;
	for (i = minpos; i < maxpos; i++)
		sum += v[i];
	return sum;
}

void *sum_t(void *seek)
{
	struct vect_sk *s = (struct vect_sk*) seek;
	s->res = sum(s->v, s->lim_inf, s->lim_sup);
	return NULL;
}
