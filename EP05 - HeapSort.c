#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX 10

void max_Heap (int m, int v[]) {
	int f = m+1;
	int t;
	
	while /*X*/ (f > 0 && v[f/2] < v[f]) {  // 
		t = v[f/2]; 
		v[f/2] = v[f];
		v[f] = t;
		f = f/2;
	}
}

void Heapify (int m, int v[]) {
	int t, f = 2;
	
	while /*X*/ (f <= m) {  // começa pelo primeiro filho
		if (f < m && v[f] < v[f+1])    //compara qual filho possui um valor maior
			++f;
		if (v[f/2] >= v[f])            //Verifica se o Pai é maior do que o filho que possui um valor maior
			break;
		t = v[f/2];
		v[f/2] = v[f];
		v[f] = t;
		f *= 2;
	}
}

void Heapsort (int n, int v[]) {
	int i, m, t, first;
	
	for (m = 1; m < n; m++) { //
		max_Heap (m-1, v);
	}
	for (m = n-1; /*X*/ m > 0; m--) { // começa pelo ultimo valor do vetor ou o ultimo filho
		t = v[1];
		v[1] = v[m];
		v[m] = t;
		Heapify (m-1, v);
	}
	for (i = 0; i < n-1; i++) {
		first = v[i];
		v[i] = v[i+1];
		v[i+1] = first;	
	}
	
}

int main () {
	int vetor[MAX];//= {13, 12, 11, 10, 14};
	int i, n = MAX, j = MAX;
	double time_spent = 0.0;
	
	clock_t begin = clock();
	
	srand(time(NULL));
	
	for (i = 0; i < MAX; i++) { //inicializar vetor com numeros aleatorios
		vetor[i] = (rand() % MAX);
		//printf("vetor[%d] = %d\n", i, vetor[i]); 
	}
	
	
/*	for (i = 0; i < MAX; i++) { //inicializar vetor com numeros em ordem crescente
		vetor[i] = i + 1;
		//printf("vetor[%d] = %d\n", i, vetor[i]); 
	}
*/	
	
/*	for (i = 0; i < MAX; i++) { //inicializar vetor com numeros em ordem decrescente
		vetor[i] = j--;
		//printf("vetor[%d] = %d\n", i, vetor[i]); 
	}
*/	
	Heapsort(n, vetor);
	
	//printf("\nVetor Ordenado\n");
	
	//for (i = 0; i < MAX; i++)
		//printf("vetor[%d] = %d\n", i, vetor[i]);	

	clock_t end = clock();
	
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	
	printf("\nTempo igual a %lf", time_spent);

	
	return 0;
}
