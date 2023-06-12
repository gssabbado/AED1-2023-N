#include <stdio.h>
#include <string.h>

#define MAX2 60


int main () {
	unsigned short N, L; // N = Qtd de Casos, L = quatidade de linhas
	char string[MAX2]; // string = tamanho da string só com letras maiusculas
	int i, j, h;
	unsigned short NumLetras, NumCaso; // Numero de letras e casos
	unsigned valorTotal; // Valor total da soma

	scanf("%hu", &N);

	for (i = 0; i < N; i++) {
		scanf("%hu", &L);

		valorTotal = 0;
		NumCaso = 0;
		for (j = 0; j < L; j++) {
			scanf(" %s", &string);

			for (h = 0; h < MAX2; h++)
                valorTotal += (string[h] - 65) + NumCaso + NumLetras++;
            NumCaso++;
            memset(string, 0, sizeof(string));

		}
        printf("%u\n", valorTotal);
    }

	return 0;
}
