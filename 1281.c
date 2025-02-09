// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 50
#define TAMANHO_MAXIMO_NOME 51

typedef struct {
    char nome[TAMANHO_MAXIMO_NOME];
    double preco;
} Produto;

typedef struct {
    char nome[TAMANHO_MAXIMO_NOME];
    int quantidade;
} Compra;

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int m, p;
        scanf("%d", &m);

        Produto produtos[MAX_PRODUTOS];
        for (int i = 0; i < m; i++) {
            scanf("%s %lf", produtos[i].nome, &produtos[i].preco);
        }

        scanf("%d", &p);
        Compra compras[MAX_PRODUTOS];
        for (int i = 0; i < p; i++) {
            scanf("%s %d", compras[i].nome, &compras[i].quantidade);
        }

        double custo_total = 0.0;
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < m; j++) {
                if (strcmp(compras[i].nome, produtos[j].nome) == 0) {
                    custo_total += compras[i].quantidade * produtos[j].preco;
                    break;
                }
            }
        }

        printf("R$ %.2f\n", custo_total);
    }

    return 0;
}
