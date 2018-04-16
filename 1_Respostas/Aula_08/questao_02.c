#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define VSIZE 50000

struct vect_sk{
	long int *v;
	int lim_inf;
	int lim_sup;
	long int res;
};

void fill_vector_50k(long int *v);
long int search_max(long int *v, int size);

void *search_max_t(void *seek);

int main(int argc, char **argv)
{
	long int v[VSIZE];

	char arg_threads[] = "-t";
	char arg_comp[] = "-c";

	if (argc < 2) {
		puts("Uso:\nquestao_02 -mode");
		puts("-mode:\n-t\tthreads\n-c\tcompleto");
		exit(-1);
	}

	if (!strcmp(argv[1], arg_comp)) {
		long int max_smax;
		fill_vector_50k(v);
		puts("Vetor inicializado");
		max_smax = search_max(v, VSIZE);
		printf("O máximo por busca completa é: %ld\n", max_smax);
	}
	
	if (!strcmp(argv[1], arg_threads)) {
		pthread_t t0, t1, t2, t3;
		long int max_t;
		struct vect_sk s0, s1, s2, s3;
		long int tv[4];

		s0.v = s1.v = s2.v = s3.v = v;
		s0.lim_inf = 0;
		s0.lim_sup = s1.lim_inf = VSIZE/4;
		s1.lim_sup = s2.lim_inf = VSIZE/2;
		s2.lim_sup = s3.lim_inf = (3*VSIZE)/4;
		s3.lim_sup = VSIZE;

		fill_vector_50k(v);
		puts("Vetor inicializado");

		pthread_create(&t0, NULL, &search_max_t, &s0);
		pthread_join(t0, NULL);

		pthread_create(&t1, NULL, &search_max_t, &s1);
		pthread_join(t1, NULL);

		pthread_create(&t2, NULL, &search_max_t, &s2);
		pthread_join(t2, NULL);

		pthread_create(&t3, NULL, &search_max_t, &s3);
		pthread_join(t3, NULL);

		tv[0] = s0.res;
		tv[1] = s1.res;
		tv[2] = s2.res;
		tv[3] = s3.res;

		max_t = search_max(tv, 4);

		printf("Máximo por 4 threads é: %ld\n", max_t);
	}
	return 0;
}


void fill_vector_50k(long int *v)
{
	int i;
	/*
	* Garantir que sempre serão gerados os mesmos números na simulação
	*/
	srandom(0);

	for (i = 0; i < VSIZE; i++)
		v[i] = random();
}

long int search_max(long int *v, int size)
{
	/*
	* Os números do vetor são sempre positivos
	*/
	long int max = 0;
	int i;

	for (i = 0; i < size; i++)
		if (v[i] > max)
			max = v[i];
	return max;
}

void *search_max_t(void *seek)
{
	struct vect_sk *s = (struct vect_sk*) seek;
	s->res = search_max(s->v, s->lim_sup - s->lim_inf);
	return NULL;
}
