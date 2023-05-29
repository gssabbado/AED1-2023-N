#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INF 0xfd3d3d3dU
#define MAX 1200

typedef unsigned uint;

uint dist[MAX];
uint graph[MAX][MAX];


void dijkstra (int C, int N, uint g[MAX][MAX], uint *d) {
	bool vis[N + 1];
	int i, j;
	int v;
	
	memset(vis, false, sizeof(vis));
	
	for (i = 0; i <= N; i++) {
		d[i] = INF;
	}
	
	d[C] = 0;
	
	for (i = 0; i <= N; i++) {
		v = -1;	
		for (j = 0; j <= N; j++) {
			if (!vis[j] && (v == -1 || d[j] < d[v]))
				v = j;
		}
		
		if (d[v] == INF)
			break;
		
		vis[v] = true;
		for (j = 0; j <= N; j++) {
			if (d[v] + g[v][j] < d[j])
				d[j] = g[v][j] + d[v];
		}
	}
} 


int main () {
	int N_Cidades, M_Rotas; //N = numero de cidades e M = numero de Rotas | 3 <= N <= 1000, 1 <= M <= N(N-1)/2
	int A, B; // Rota de A até B | 1 <= A,B <= N, A != B
	int C, R, E; // C - Curytyba, R - Riacho de Fevereiro e E - Estatunido
	int i, j;
	
	
	while (scanf("%d %d", &N_Cidades, &M_Rotas) != EOF) {
		for (i = 0; i <= N_Cidades; ++i) {
			for (j = 0; j <= N_Cidades; j++) {
				graph[i][j] = INF;  
			}
		}
		for (i = 0; i < M_Rotas; i++) {
			scanf("%d %d", &A, &B);
			graph[A][B] = graph[B][A] = 1;
		}
		
		scanf("%d %d %d", &C, &R, &E);
		
		for (i = 0; i <= N_Cidades; i++)
			graph[E][i] = graph[i][E] = INF;
		
		dijkstra(C, N_Cidades, graph, dist);
		
		printf("%d\n", dist[R]);
	}
	
	
	return 0;
}

