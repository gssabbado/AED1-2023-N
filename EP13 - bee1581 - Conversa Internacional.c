#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main () {
	int N, K; // N = numero de casos teste, K = numero de pessoas
	char S[21], antes[21]; // S = lingua da pessoa, antes = compara a lingua da pessoa anterior com a atual
	bool nativo;  // nativo = idioma nativo usado é o ingles, caso não tenha pessoas com o mesmo idioma nativo
	int i, j, aux; // aux = auxiliar para nao entrar no laço condicional na primeira vez do loop

	scanf("%d", &N);

	for (i = 0; i < N; i++){

		scanf("%d", &K);
		
		nativo = false;
		aux = 0;	
		for (j = 0; j < K; j++) {		
			scanf(" %s", &S);
			getchar();		
		
			if (strcmp(S,antes) != 0 && nativo == false && aux != 0) {
				nativo = true;
			}
			else
				strcpy(antes, S);
			aux++;
		}
			
			
		if (nativo) {
			printf("ingles");
		    printf("\n");
		} 
		else {
			printf("%s", S);
		    printf("\n");
		}
		
	}
	
	return 0;
}
