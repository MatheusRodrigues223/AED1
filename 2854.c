// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 300

int pai[MAX];

int encontrar(int x) {
    if (pai[x] != x) {
        pai[x] = encontrar(pai[x]);
    }
    return pai[x];
}

void unir(int x, int y) {
    int raizX = encontrar(x);
    int raizY = encontrar(y);
    if (raizX != raizY) {
        pai[raizY] = raizX;
    }
}

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    char nomes[M][31];
    int nome_para_indice[M];
    int indice = 0;

    for (int i = 0; i < M; i++) {
        pai[i] = i;
    }

    for (int i = 0; i < N; i++) {
        char nome1[31], relacao[31], nome2[31];
        scanf("%s %s %s", nome1, relacao, nome2);

        int indice1 = -1, indice2 = -1;
        for (int j = 0; j < indice; j++) {
            if (strcmp(nomes[j], nome1) == 0) {
                indice1 = j;
            }
            if (strcmp(nomes[j], nome2) == 0) {
                indice2 = j;
            }
        }

        if (indice1 == -1) {
            strcpy(nomes[indice], nome1);
            nome_para_indice[indice] = indice;
            indice1 = indice++;
        }

        if (indice2 == -1) {
            strcpy(nomes[indice], nome2);
            nome_para_indice[indice] = indice;
            indice2 = indice++;
        }

        unir(indice1, indice2);
    }

    int familias = 0;
    int raizes_unicas[MAX] = {0};

    for (int i = 0; i < M; i++) {
        int raiz = encontrar(i);
        if (!raizes_unicas[raiz]) {
            raizes_unicas[raiz] = 1;
            familias++;
        }
    }

    printf("%d\n", familias);

    return 0;
}
