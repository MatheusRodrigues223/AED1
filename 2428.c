// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <stdbool.h>

bool verificar(int aA, int aB, int aC, int aD) {
	return (aA * aB == aC * aD);
}


int main() {

    int A, B, C, D;

	while (scanf(" %d %d %d %d", &A, &B, &C, &D) != EOF) {
		if (verificar(A, B, C, D) || verificar(A, D, B, C) || verificar(A, C, D, B)) {
			printf("S\n");
		} else {
			printf("N\n");	
		}
	}

	return 0;
}
