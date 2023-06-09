#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Estrutura da celula
typedef struct cel { 
	char nome[30];
	struct cel* prox;
}celula;

// Cria��o de uma c�lula para lista
celula* criarCelula (char nomes[]) {
	celula *nova;
	
	nova = (celula*) malloc(sizeof(celula));
	strcpy(nova->nome, nomes);
	nova->prox = NULL;
	
	return nova;
}

//Insere nome no final da lista
celula* InserirNoFinal (celula *head, char nomes[]) { 
	celula *nova, *aux;

	if (head == NULL) {
		head = criarCelula(nomes);
		return head;
	}
	
	for (nova = head; nova->prox != NULL; nova = nova->prox);

	nova->prox = criarCelula(nomes);
	
	return head;
}

// Imprimi a lista
void Imprimir(celula *head) { 
	celula *aux;
	aux = head;
	
	
	for(aux = head; aux != NULL; aux = aux->prox) {
		if (aux->prox != NULL) printf("%s ", aux->nome);
		else if (aux->prox == NULL) printf("%s", aux->nome);
	}
	printf("\n");
}

int main () {
	celula *head = NULL;        // cabeca da lista
	celula *aux, *aux2;
	char L[100], N[100];
	char S[30];
	char *token, *token2;
	char nome[30];
	char *ajuda;               // ajuda a pegar o endere�o da lista Atual e n�o perder o token quando a lista Nova for inserida no meio da lista Atual.
		
	ajuda = L;
	
	scanf("%[^\n]", &L);
	getchar();
	scanf("%[^\n]", &N);
	getchar();
	scanf("%[^\n]", &S);
	

	if(strcmp(S, "nao") == 0){  // Caso 1: N�o houver indica��o da lista para algum amigo
		token = strtok(L, " ");
		while (token != NULL) {
			head = InserirNoFinal(head, token);
			token = strtok(NULL, " ");
		}	
		
		token = strtok(N, " ");
		while (token != NULL) {
			head = InserirNoFinal(head, token);
			token = strtok(NULL, " ");
		}	
		Imprimir(head);
	}
	else {                      // Caso 2: Indica��o da lista para algum amigo
		//token = strtok(L, " ");
		while (token = strtok_r(ajuda, " ", &ajuda)) {
			strcpy(nome, token);
			if (strcmp(nome, S) == 0) {	
				token2 = strtok(N, " " );
				while (token2 != NULL) {
					head = InserirNoFinal(head, token2);
					token2 = strtok(NULL, " ");
				}
			}
		head = InserirNoFinal(head, token);
		}	
		Imprimir(head);	
	}
	
	aux = head;
	while (aux != NULL) {       // Libera��o da mem�ria alocada
		aux2 = aux;
		aux = aux->prox;
		free(aux2);
	}

	return 0;
}
