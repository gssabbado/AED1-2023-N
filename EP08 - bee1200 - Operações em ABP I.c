#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel {
	char letra;
	char chave;
	struct cel *esq;
	struct cel *dir;
}node;

typedef node *arvore;

int cont = 0;

node *criaNode (char letra) {
	node *novo;
	novo = (node*) malloc(sizeof(node));
	novo->chave = letra;
	novo->esq = novo->dir = NULL;
	return novo;
}


arvore Insere (arvore r, char letra) {
	node *f, *p, *novo;
	
	novo = criaNode(letra);
	
	if (r == NULL) 
		return novo;
		
	f = r;
	while (f != NULL) {
		p = f;
		if (f->chave > novo->chave)
			f = f->esq;
		else
			f = f->dir;
	}
	if (p->chave > novo->chave) 
		p->esq = novo;
	else
		p->dir = novo;
	
	return r;
}

// r-e-d = prefixa
// e-r-d = infixa
// e-d-r = posfixa
void imprimiPre (arvore r) {
	if (r != NULL) {
		cont--;
		if(cont == 0) {
			printf("%c", r->chave);
		}
		printf("%c ", r->chave);
		imprimiPre (r->esq);
		imprimiPre (r->dir);
	}
}

void imprimiIn (arvore r) {
	if (r != NULL) {
		imprimiIn (r->esq);
		if(cont == 0) {
			printf("%c", r->chave);
		}
		printf("%c ", r->chave);
		cont--;		
		imprimiIn (r->dir);
	}
}

void imprimiPos (arvore r) {
	if (r != NULL) {
		imprimiPos (r->esq);
		imprimiPos (r->dir);
		if(cont == 0) {
			printf("%c", r->chave);
		}
		printf("%c ", r->chave);
		cont--;	
	}
}

node *Buscar (arvore r, char letra) {
	if (r == NULL || r->chave == letra)
		return r;
	if (r->chave > letra)
		return Buscar (r->esq, letra);
	else 
		return Buscar (r->dir, letra);
}


int main () {
	arvore r = NULL;
	int k, N;
	node *folhaNova, *folhaB;
	char comando[20], letra;
	
	
	while (scanf("%s%*c", comando) != EOF) {
		
		if (strcmp(comando, "I") == 0) {
			scanf("%c", &letra);
			r = Insere(r, letra);
			cont++;
		}
		else if (strcmp(comando, "INFIXA") == 0) {
			imprimiIn(r);
			printf("\n");
		}
		else if (strcmp(comando, "PREFIXA") == 0) {
			imprimiPre(r);
			printf("\n");
		}
		else if (strcmp(comando, "POSFIXA") == 0) {
			imprimiPos(r);
			printf("\n");
		}
		else if (strcmp(comando, "P") == 0) {
			scanf("%c", &letra);
			folhaB = Buscar(r, letra);
			if (folhaB != NULL)
				printf("%c existe\n", letra);
			else
				printf("%c nao existe\n", letra);
		} 
	}
	free(r);	
	return 0;
}
