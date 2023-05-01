#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX 5000

void Selection (int n, int v[]) {
	int i, j, min, x;
	
	for (i = 0; /*A*/ i < n - 1; i++) {             // Invariante A: 1. v[0...n-1] é uma permutação do vetor original 
		min = i;                                //               2. v[0...i-1] está em ordem crescente
		for (j = i + 1; j < n; j++) {           //               3. v[i - 1] <= v[j] para j = i, i+1,..., n-1
			if (v[j] < v[min]) 
				min = j;
			x = v[i];
			v[i] = v[min];
			v[min] = x;
		}
	}
}

int main () {
	int vetor[MAX];
	int i, n = MAX, j = MAX;
	double time_spent = 0.0;
	
	clock_t begin = clock();
	
	srand(time(NULL));
	
/*	for (i = 0; i < MAX; i++) {                   //inicializar vetor com numeros aleatorios
		vetor[i] = (rand() % MAX);
		//printf("vetor[%d] = %d\n", i, vetor[i]); 
	}
*/	
	
/*	for (i = 0; i < MAX; i++) {                   //inicializar vetor com numeros em ordem crescente
		vetor[i] = i;
		//printf("vetor[%d] = %d\n", i, vetor[i]); 
	}
*/	
	
	for (i = 0; i < MAX; i++) {                   //inicializar vetor com numeros em ordem decrescente
		vetor[i] = j--;
		//printf("vetor[%d] = %d\n", i, vetor[i]); 
	}
	
	Selection(n, vetor);
	
	//printf("\nVetor Ordenado\n");
	
	//for (i = 0; i < MAX; i++)
		//printf("vetor[%d] = %d\n", i, vetor[i]);	

	clock_t end = clock();
	
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	
	printf("\nTempo igual a %lf", time_spent);

	
	return 0;
}
