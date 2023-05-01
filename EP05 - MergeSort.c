#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX 5000

void Mergesort (int p, int r, int v[]) {
	int q;
	
	if (p < r - 1) {
		q = (p + r)/2;
		Mergesort (p, q, v);
		Mergesort (q, r, v);
		Intercalate (p, q, r, v);	
	}
}

void Intercalate (int p, int q, int r, int v[]) {
	int i, j , k, *w;
	w = (int*) malloc ((r-p) * sizeof (int));
	i = p;
	j = q;
	k = 0;
	
	while (i < q && j < r) {
		if (v[i] <= v[j])
			w[k++] = v[i++];
		else 
			w[k++] = v[j++];
	}
	while (i < q) w[k++] = v[i++];
	while (j < r) w[k++] = v[j++];
	for (i = p; i < r; i++)
		v[i] = w[i-p];
	free (w);
}

int main () {
		int vetor[MAX];
	int i, n = MAX, j = MAX;
	double time_spent = 0.0;
	
	clock_t begin = clock();
	
	srand(time(NULL));
	
/*	for (i = 0; i < MAX; i++) { //inicializar vetor com numeros aleatorios
		vetor[i] = (rand() % MAX);
		//printf("vetor[%d] = %d\n", i, vetor[i]); 
	}
*/	
	
/*	for (i = 0; i < MAX; i++) { //inicializar vetor com numeros em ordem crescente
		vetor[i] = i;
		//printf("vetor[%d] = %d\n", i, vetor[i]); 
	}
*/	
	
	for (i = 0; i < MAX; i++) { //inicializar vetor com numeros em ordem decrescente
		vetor[i] = j--;
		//printf("vetor[%d] = %d\n", i, vetor[i]); 
	}
	
	Mergesort(0, n, vetor);
	
	//printf("\nVetor Ordenado\n");
	
/*	for (i = 0; i < MAX; i++)
		printf("vetor[%d] = %d\n", i, vetor[i]);	
*/
	clock_t end = clock();
	
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	
	printf("\nTempo igual a %lf", time_spent);

	
	return 0;

	
}
