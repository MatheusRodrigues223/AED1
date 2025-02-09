// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1024

int desloc_x[] = {-1, 1, 0, 0};
int desloc_y[] = {0, 0, -1, 1};

char imagem[MAX][MAX];
bool visitado[MAX][MAX];
int N, M;

void preencher_regiao(int x, int y) {
    static int fila[MAX * MAX][2];
    int frente = 0, tras = 0;
    
    fila[tras][0] = x;
    fila[tras][1] = y;
    tras++;
    visitado[x][y] = true;
    
    while (frente < tras) {
        int cx = fila[frente][0];
        int cy = fila[frente][1];
        frente++;
        
        for (int i = 0; i < 4; i++) {
            int nx = cx + desloc_x[i];
            int ny = cy + desloc_y[i];
            
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visitado[nx][ny] && imagem[nx][ny] == '.') {
                visitado[nx][ny] = true;
                fila[tras][0] = nx;
                fila[tras][1] = ny;
                tras++;
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; i++) {
        scanf("%s", imagem[i]);
    }
    
    memset(visitado, 0, sizeof(visitado));
    int cliques = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (imagem[i][j] == '.' && !visitado[i][j]) {
                preencher_regiao(i, j);
                cliques++;
            }
        }
    }
    
    printf("%d\n", cliques);
    
    return 0;
}
