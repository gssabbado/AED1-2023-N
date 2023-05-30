#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 1200

void Caminho (int C, int N, unsigned int G[MAX][MAX], unsigned int *d) {
	bool visitado[N + 1];
	int i, j;
	int aux;
	
	for (i = 0; i < N + 1; i++)
		visitado[i] = false;
	
	for (i = 0; i <= N; i++) {
		d[i] = INT_MAX;
	}
	
	d[C] = 0;
	
	for (i = 0; i <= N; i++) {
		aux = -1;	
		for (j = 0; j <= N; j++) {
			if (!visitado[j] && (aux == -1 || d[j] < d[aux]))
				aux = j;
		}
		
		if (d[aux] == INT_MAX)
			break;
		
		visitado[aux] = true;
		for (j = 0; j <= N; j++) {
			if (d[aux] + G[aux][j] < d[j])
				d[j] = G[aux][j] + d[aux];
		}
	}
} 


int main () {
	unsigned int G[MAX][MAX];
	unsigned int dist[MAX];
	int N_Cidades, M_Rotas; //N = numero de cidades e M = numero de Rotas | 3 <= N <= 1000, 1 <= M <= N(N-1)/2
	int A, B; // Rota de A até B | 1 <= A,B <= N, A != B
	int C, R, E; // C - Curytyba, R - Riacho de Fevereiro e E - Estatunido
	int i, j;
	
	
	while (scanf("%d %d", &N_Cidades, &M_Rotas) != EOF) {
		
		for (i = 0; i <= N_Cidades; ++i) {
			for (j = 0; j <= N_Cidades; j++) {
				G[i][j] = INT_MAX;  // 
			}
		}
	
		for (i = 0; i < M_Rotas; i++) {
			scanf("%d %d", &A, &B);
			G[A][B] = G[B][A] = 1;
		}
		
		scanf("%d %d %d", &C, &R, &E);
		
		for (i = 0; i <= N_Cidades; i++)
			G[E][i] = G[i][E] = INT_MAX;
		
		Caminho(C, N_Cidades, G, dist);

		
		printf("%d\n", dist[R]);
	}
	
	return 0;
}
