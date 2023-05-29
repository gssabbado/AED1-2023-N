// Prefixa, Infixa e Pósfixa
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
	char letra;
	struct celula *esq;
	struct celula *dir;
} node;

node *criaNode (char letra) {
	node *novo;
	novo = (node*) malloc(sizeof(node));
	novo->letra = letra;
	novo->esq = NULL;
	novo->dir = NULL;
	
	return novo;
}

node *arvore (char infixo[], char prefixo[], int inicio, int final, int *indicePrefixo) {
	if (inicio > final) {
		return NULL;
	}

	node *novo = criaNode(prefixo[*indicePrefixo]);
	(*indicePrefixo)++;
	
	if (inicio == final) {
		return novo;
	}
		
	int indiceInfixo = strchr(infixo, novo->letra) - infixo;              
	novo->esq = arvore(infixo, prefixo, indiceInfixo - 1, inicio, indicePrefixo);
	novo->dir = arvore(infixo, prefixo, final, indiceInfixo + 1, indicePrefixo );

	return novo;
}

void imprimePos (node *r) {
	if(r != NULL) {
		imprimePos (r->esq);
		imprimePos (r->dir);
		printf("%c", r->letra);
	}
}


int main () {
	node *r;
	int C, N; // C <= 2000 e 1 <= N <= 52
	char S1[53], S2[53]; // S1 percurso prefixo (r-e-d), S2 percurso infixo (e-r-d)
	int i, indice;
	scanf("%d", &C);

	for (i = 0; i < C; i++) {
		scanf("%d %s %s", &N, &S1, &S2);
		indice = 0;
		r = arvore(S2, S1, 0,  N - 1, &indice);
		imprimePos(r);
		printf("\n");
		free(r);
	}
	
	return 0;
}
