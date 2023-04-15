#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Estrutura da celula
typedef struct cel { 
	char nome[30];
	struct cel* prox;
}celula;

// Criação de uma célula para lista
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


// Buscar a celula e inserir a lista nova no meio da lista atual
celula* InserirNoMeio (celula *head, celula *head2, char indicado[]) { 
	celula *anterior, *aux, *amigo;
	
	strcpy(amigo->nome, indicado);
	aux = head;

	while (aux != NULL && strcmp(amigo->nome, indicado) != 0) {
		anterior = aux;
		aux = aux->prox;
	}
	anterior->prox = head2;
	while (head2 != NULL) {
		head2 = head2->prox;
	}
	head2->prox = aux;

	return head;
}

// Imprimi a lista
void Imprimir(celula *head) { 
	celula *aux;
	
	for(aux = head; aux != NULL; aux = aux->prox)
		printf("%s ", aux->nome);
	
}

int main () {
	celula *head = NULL;        // cabeca da lista Atual
	celula *head2 = NULL;       // cabeca da lista Nova
	celula *aux, *aux2;
	char L[100], N[100];
	char S[30];
	char *token, *token2;
	
	scanf("%[^\n]", &L);
	getchar();
	scanf("%[^\n]", &N);
	getchar();
	scanf("%[^\n]", &S);
	

	if(strcmp(S, "nao") == 0){  // Caso 1: Não houver indicação da lista para algum amigo
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
	else {                      // Caso 2: Indicação da lista para algum amigo
		token = strtok(L, " ");
		while (token != NULL) {
			head = InserirNoFinal(head, token);
			token = strtok(NULL, " ");
		}	
		
		token2 = strtok(N, " ");
		while (token2 != NULL) {
			head2 = InserirNoFinal(head2, token2);
			token2 = strtok(NULL, " ");
		}
		head = InserirNoMeio(head, head2, S);
		
		Imprimir(head);	
	}
	
	aux = head;
	while (aux != NULL) {       // Liberação da memória alocada
		aux2 = aux;
		aux = aux->prox;
		free(aux2);
	}

	
	return 0;
}
