#include <stdio.h>
#include <stdlib.h>

typedef struct cel{

	int numero;
	struct cel *esquerda;
	struct cel *direita;

} no;


no* insere(no *r, int numero) {

	if (!r) {
		r = (no*) malloc(sizeof(no));
		r->numero = numero;
		r->esquerda = r->direita = NULL;

	}
	else if (r->numero > numero)
		r->esquerda = insere(r->esquerda, numero);

	else
		r->direita = insere(r->direita, numero);

	return r;

}

void ImprimiPre(no *r) {

	if (r != NULL) {
		printf(" %d", r->numero);
		ImprimiPre(r->esquerda);
		ImprimiPre(r->direita);
	}

}


void ImprimiIn(no *r) {

	if (r != NULL) {
		ImprimiIn(r->esquerda);
		printf(" %d", r->numero);
		ImprimiIn(r->direita);
	}

}

void ImprimiPos(no *r) {

	if (r != NULL) {
		ImprimiPos(r->esquerda);
		ImprimiPos(r->direita);
		printf(" %d", r->numero);
	}
}

void erase(no *r) {
	if (r != NULL)
	{
		erase(r->esquerda);
		erase(r->direita);
		free(r);
		r = NULL;
	}

}

int main () {

	unsigned short i;
	int numero;

	unsigned short qtsNos;
	unsigned short qtsCasos, caso = 0;

	scanf("%hu", &qtsCasos);

	while (qtsCasos--) {

		no *r = NULL;
		scanf("%hu", &qtsNos);

		for (i = 0; i < qtsNos; i++) {

			scanf("%d", &numero);
			r = insere(r, numero);

		}

		printf("Case %hu:\n", ++caso);
		printf("Pre.:");
		ImprimiPre(r);
		printf("\n");
		printf("In..:");
		ImprimiIn(r);
		printf("\n");
		printf("Post:");
		ImprimiPos(r);
		printf("\n\n");
		erase(r);

	}
	return 0;
}

