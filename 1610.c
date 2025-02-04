// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 10000
#define MAX_M 30000

typedef struct ListaAdj {
    int vertice;
    struct ListaAdj *prox;
} ListaAdj;

typedef struct Grafo {
    int V;
    int E; 
    ListaAdj *adj[MAX_N];
} Grafo;

void inicializa_grafo(Grafo *grafo, int V, int E) {
    grafo->V = V;
    grafo->E = E;
    for (int i = 0; i < V; i++) {
        grafo->adj[i] = NULL;
    }
}

void adiciona_aresta(Grafo *grafo, int u, int v) {
    ListaAdj *novo = (ListaAdj*) malloc(sizeof(ListaAdj));
    novo->vertice = v-1;
    novo->prox = grafo->adj[u-1];
    grafo->adj[u-1] = novo;
}

bool dfs(int v, bool visitado[], bool rec_stack[], Grafo *grafo) {
    if (!visitado[v]) {
        visitado[v] = true;
        rec_stack[v] = true;

        ListaAdj *adjacente = grafo->adj[v];
        while (adjacente != NULL) {
            int u = adjacente->vertice;
            if (!visitado[u] && dfs(u, visitado, rec_stack, grafo)) {
                return true;
            } else if (rec_stack[u]) {
                return true;
            }
            adjacente = adjacente->prox;
        }
    }
    rec_stack[v] = false;
    return false;
}

bool tem_ciclo(Grafo *grafo) {
    bool visitado[MAX_N] = { false };
    bool rec_stack[MAX_N] = { false };

    for (int i = 0; i < grafo->V; i++) {
        if (dfs(i, visitado, rec_stack, grafo)) {
            return true;
        }
    }
    return false;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        Grafo grafo;
        inicializa_grafo(&grafo, N, M);

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            adiciona_aresta(&grafo, A, B);
        }

        if (tem_ciclo(&grafo)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }

        for (int i = 0; i < N; i++) {
            ListaAdj *adjacente = grafo.adj[i];
            while (adjacente != NULL) {
                ListaAdj *temp = adjacente;
                adjacente = adjacente->prox;
                free(temp);
            }
        }
    }

    return 0;
}
