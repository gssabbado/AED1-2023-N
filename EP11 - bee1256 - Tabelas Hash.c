// Hash usa pra grande quantidade de dados| ele troca o processamento pela memoria
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

typedef struct cel {
	int conteudo;
	struct cel *prox;
}no;

typedef struct lista {
	no *head;
	no *tail;
}listDes;

// Inicializa o Vetor com o tamanho igual M-1
void initialize (listDes Tam[], int tamanho) {
	int i;
	for (i = 0; i < tamanho; i++) {
		Tam[i].head = NULL;
		Tam[i].tail = NULL;
	}
}

// Insere os valores na tabelas
void hash (listDes Tam[], int valor, int chave) {
	no* aux;
	
	aux = (no*) malloc(sizeof(no));
	if (!aux) exit(1); 
	aux->conteudo = valor;
	aux->prox = NULL;
	
	if (Tam[chave].head == NULL)
		Tam[chave].head = aux;
	else
		Tam[chave].tail->prox = aux;
	
	Tam[chave].tail = aux;
}

void imprimi (no *head, int indice) {
	int i, j;
	no *aux;
	printf("%d -> ", indice);
	for (aux = head; aux; aux = aux->prox) {
		printf("%d -> ", aux->conteudo);
	}		
	printf("\\");
	printf("\n");
}



int main () {
	listDes Tam[MAX];
	int N, M, C; // N = Qtd de Casos, M = Num de endereços-base, C = Qtd de chaves a serem armazenadas
	int i, j, valor;

	scanf("%d", &N);
	
	
	for (i = 0; i < N; i++) {
		scanf("%d %d", &M, &C);
		initialize(Tam, M);
			
		for (j = 0; j < C; j++) {
			scanf("%d", &valor);
			hash(Tam, valor, valor % M);
		}
		for (j = 0; j < M; j++)
			imprimi(Tam[j].head, j);
		if (i + 1 < N)
			printf("\n");
	}
	
	return 0;
}
