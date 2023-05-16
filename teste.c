//Funciona

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100000

void trivial (char palavra[], char texto[]) {
	int k, r, cont = 0;
	int m, n;
	
	m = strlen(palavra);
	n = strlen(texto);
	
	for (k = 0, r = 0; k < n; k++) {
		if (palavra[r] == texto[k]) {
			r++;
			cont++;
		}
		else if (cont == 5) break;
		else {
			r = 0;
			cont = 0;
		}
	}
	if (cont == 5) printf("Link Bolado\n");
	else printf("Link Tranquilo\n");
}


int main () {
	char S[MAX], palavra[5] = "zelda";
	int i;
	
	scanf("%[^\n]", &S);
	for (i = 0; i < MAX; i++)
		S[i] = tolower(S[i]);
		
	trivial(palavra, S);
	
	
	return 0;
}
