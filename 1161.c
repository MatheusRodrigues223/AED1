// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>

unsigned long long fatorial(int numero) {
    unsigned long long resultado = 1;
    for (int i = 1; i <= numero; i++) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    int M, N;

    while (scanf("%d %d", &M, &N) != EOF) {
        unsigned long long fatorialM = fatorial(M);
        unsigned long long fatorialN = fatorial(N);
        printf("%llu\n", fatorialM + fatorialN);
    }

    return 0;
}
