#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX 5000

int Divide (int p, int r, int v[]) {
	int c, j, k, t;
	c = v[r];
	j = p;
	for (k = p; /*A*/ k < r; k++) {
		if (v[k] <= c) {
			t = v[j];
			v[j] = v[k];
			v[k] = t;
			j++;
		}
	}
	v[r] = v[j];
	v[j] = c;
	return j;
}

void Quicksort (int p, int r, int v[]) {
	int j;
	if (p < r) {
		j = Divide (p, r, v);
		Quicksort (p, j - 1, v);
		Quicksort (j + 1, r, v);
	}
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
	
	Quicksort(0, n, vetor);
	
	//printf("\nVetor Ordenado\n");
	
	//for (i = 0; i < MAX; i++)
		//printf("vetor[%d] = %d\n", i, vetor[i]);	

	clock_t end = clock();
	
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	
	printf("\nTempo igual a %lf", time_spent);

	
	return 0;
}
