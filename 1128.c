// Matheus da Rosa Rodrigues
// RA: 176614


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 2000

int adj[MAXN][MAXN];
int adjT[MAXN][MAXN];
int visitado[MAXN];
int ordem[MAXN];
int ordemIndex;

void dfs1(int v, int N) {
    visitado[v] = 1;
    for (int i = 0; i < N; i++) {
        if (adj[v][i] && !visitado[i]) {
            dfs1(i, N);
        }
    }
    ordem[ordemIndex++] = v;
}

void dfs2(int v, int N) {
    visitado[v] = 1;
    for (int i = 0; i < N; i++) {
        if (adjT[v][i] && !visitado[i]) {
            dfs2(i, N);
        }
    }
}

int main() {
    int N, M;
    while (scanf("%d %d", &N, &M) && N && M) {
        memset(adj, 0, sizeof(adj));
        memset(adjT, 0, sizeof(adjT));

        for (int i = 0; i < M; i++) {
            int V, W, P;
            scanf("%d %d %d", &V, &W, &P);
            V--; 
            W--;

            adj[V][W] = 1;
            adjT[W][V] = 1;
            if (P == 2) {
                adj[W][V] = 1;
                adjT[V][W] = 1;
            }
        }

        memset(visitado, 0, sizeof(visitado));
        ordemIndex = 0;

        for (int i = 0; i < N; i++) {
            if (!visitado[i]) {
                dfs1(i, N);
            }
        }

        memset(visitado, 0, sizeof(visitado));

        int fortementeConectado = 1;

        dfs2(ordem[ordemIndex - 1], N);
        
        for (int i = 0; i < N; i++) {
            if (!visitado[i]) {
                fortementeConectado = 0;
                break;
            }
        }

        printf("%d\n", fortementeConectado);
    }
    return 0;
}

