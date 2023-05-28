#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct graph {
	int l;
	int h;	
	char **adj;
}Graph;


Graph* init(int largura, int altura) {  
	int i;
	Graph *G ;
	G = (Graph*) malloc(sizeof(Graph));
	G->l = largura;
	G->h = altura;
	
	G->adj = (char**) malloc(sizeof(char*) * altura);
	for (i = 0; i < altura; i++) {
		G->adj[i] = (char *) malloc(sizeof(char) * (largura + 1));
	}
	
	return G;
}

void freeGraph (Graph *G) {
	int i;
	Graph *aux = G;
	
	if (G == NULL)
		return;
	
	for (i = 0; i < aux->h; i++) {
		free(aux->adj[i]);
	}
	free(aux->adj);
	free(aux);
}


int main () {
	Graph *G;
	int x, y, i, j;            // x = largura, y = altura 
	int a = 0, b = 0;           // a = largura, b = altura
	int position[MAX][MAX];
	char aux;
	
	scanf("%d", &x);
	scanf("%d", &y);
		
	G = init(x, y);
	
	for (i = 0; i < y; i++) {
		scanf("%s", G->adj[i]);
	}
	for (i = 0; i < y; i++) {
		for (j = 0; j < x; j++)
			position[i][j] = 0;
	}
	
	while (1) {
		// Verifica se esta fora do mapa
		if (position[b][a]) 
			break;
		
		if (a >= x || b >= y || a < 0 || b < 0) 
			break;
			
	
		position[b][a] = 1; // Primeira posição visitada
	
		aux = G->adj[b][a]; // Pega o simbolo da posição visitada

		// Chega o simbolo e atualiza posição
		if (aux == '>') {
			a++;
		}
		else if (aux == '<') {
			a--;
		}
		else if (aux == 'v') {
			b++;
		}
		else if (aux == '^') {
			b--;
		}
		else if (aux == '*') {
			printf("*\n");
			return 0;
		}
		else if (aux == '.') {
			if (a < G->l - 1) {
				a++;
			}
			else if (b < G->h - 1) {
				a = 0;
				b++;
			}
		}	
	}
	
	printf("!\n");
	    
	freeGraph(G);
	
	return 0;
}
