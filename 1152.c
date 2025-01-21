// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, custo;
} Aresta;

int Comparar(const void *a, const void *b) {
    return ((Aresta *)a) -> custo - ((Aresta *)b) -> custo;
}

int Encotrar(int *pai, int i) {
    if (pai[i] != i) {
        pai[i] = Encotrar(pai, pai[i]);
    }
    return pai[i];
}

void union_set(int *pai, int *nivel, int u, int v) {
    int raiz_u = Encotrar(pai, u);
    int raiz_v = Encotrar(pai, v);
    if (nivel[raiz_u] < nivel[raiz_v]) {
        pai[raiz_u] = raiz_v;
    } else if (nivel[raiz_u] > nivel[raiz_v]) {
        pai[raiz_v] = raiz_u;
    } else {
        pai[raiz_v] = raiz_u;
        nivel[raiz_u]++;
    }
}

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n) && m && n) {
        Aresta Arestas[n];
        int custoTotal = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &Arestas[i].u, &Arestas[i].v, &Arestas[i].custo);
            custoTotal += Arestas[i].custo;
        }
        qsort(Arestas, n, sizeof(Aresta), Comparar);

        int pai[m], nivel[m];
        for (int i = 0; i < m; i++) {
            pai[i] = i;
            nivel[i] = 0;
        }

        int custoMST = 0;
        for (int i = 0; i < n; i++) {
            if (Encotrar(pai, Arestas[i].u) != Encotrar(pai, Arestas[i].v)) {
                union_set(pai, nivel, Arestas[i].u, Arestas[i].v);
                custoMST += Arestas[i].custo;
            }
        }

        printf("%d\n", custoTotal - custoMST);
    }
    return 0;
}
