#include <stdio.h>

int main () {
	int X[10];
	int valor, i;
	
	for (i = 0; i < 10; i++) {                    //Entrada de valores no Vetor
		scanf("%d", &X[i]);
	}
	
	for (i = 0; i < 10; i++) {                    // La�o para imprimir os valores do vetor
		if (X[i] <= 0) {                          // Se o valor for menor ou igual a 0, ent�o � impresso 1 no lugar
			X[i] = 1;                             // Se o valor for maior que 0, ent�o � impresso o valor atual
			printf("X[i] = %d", X[i]);
		}
		else {
			printf("X[%d] = %d", i, X[i]);
		}
		printf("\n");
	}
	
	
	return 0;
}
