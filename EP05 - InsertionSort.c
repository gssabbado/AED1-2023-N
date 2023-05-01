#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX 5000

void Insertion (int n, int v[]) {
	int i, j, x;
	
	for (j = 1; /*A*/ j < n; j++) {               // Invariante A: 1. o vetor v[0...n-1] é uma permutação do vetor original
		x = v[j];                                 //               2. o vetor[0...j-1] é crescente
		for (i = j - 1; i >= 0 && v[i] > x; i--) 
			v[i + 1] = v[i];
		v[i + 1] = x;
	}
}



int main () {
	int vetor[MAX];
	int i, n = MAX, j = MAX;
	double time_spent = 0.0;
	
	clock_t begin = clock();
	
	srand(time(NULL));
	
/*	for (i = 0; i < MAX; i++) {         //inicializar vetor com numeros aletorios entre 0 e MAX
		vetor[i] = (rand() % MAX);
		//printf("vetor[%d] = %d\n", i, vetor[i]); 
	}
*/	
/*	for (i = 0; i < MAX; i++) {        //inicializar vetor com numeros em ordem crescente
		vetor[i] = i;
		//printf("vetor[%d] = %d\n", i, vetor[i]); 
	}
*/

	for (i = 0; i < MAX; i++) {       //inicializar vetor com numeros em ordem decrescente
		vetor[i] = j--;
		//printf("vetor[%d] = %d\n", i, vetor[i]); 
	}
	
	Insertion(n, vetor);
	
	//printf("\nVetor Ordenado\n"); 
	
	//for (i = 0; i < MAX; i++)
		//printf("vetor[%d] = %d\n", i, vetor[i]);	

	clock_t end = clock();
	
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	
	printf("\nTempo igual a %lf", time_spent);

	
	return 0;
}
