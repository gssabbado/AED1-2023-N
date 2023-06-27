#include <stdio.h>
#include <string.h>

int main () {
	int n, k, i, j;
	char nomes[100][21];
	char aux[21];
	
	scanf("%d %d", &n, &k);
	if (n >= 1 && n <= 100 && k >= 1 && k <= 100) {
		for (i = 0; i < n; i++) {
			scanf("%s", &nomes[i]);
		}
		for (i = 0; i < n - 1; i++) {
			for (j = i + 1; j < n; j++) {
				if (strcmp(nomes[i], nomes[j]) > 0) {
					strcpy(aux, nomes[i]);
					strcpy(nomes[i], nomes[j]);
					strcpy(nomes[j], aux);
				}
			}
		}
	}
	printf("%s", nomes[k - 1]);
	printf("\n");
	
	return 0;
}
