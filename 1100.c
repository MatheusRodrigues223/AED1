// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x, y;
} Posicao;

typedef struct {
    Posicao posicao;
    int movimentos;
} No;

int Valido(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int bfs(Posicao comeco, Posicao fim) {
    int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
    int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};
    int visitado[8][8];
    memset(visitado, 0, sizeof(visitado));
    
    No fila[8 * 8];
    int frente = 0, traseira = 0;
    fila[traseira++] = (No){comeco, 0};
    visitado[comeco.x][comeco.y] = 1;
    
    while (frente < traseira) {
        No atual = fila[frente++];
        
        if (atual.posicao.x == fim.x && atual.posicao.y == fim.y) {
            return atual.movimentos;
        }
        
        for (int i = 0; i < 8; i++) {
            int nx = atual.posicao.x + dx[i];
            int ny = atual.posicao.y + dy[i];
            
            if (Valido(nx, ny) && !visitado[nx][ny]) {
                visitado[nx][ny] = 1;
                fila[traseira++] = (No){{nx, ny}, atual.movimentos + 1};
            }
        }
    }
    return -1;
}

Posicao parsePosicao(char *posicao) {
    return (Posicao){posicao[0] - 'a', posicao[1] - '1'};
}

int main() {
    char comeco[3], fim[3];
    while (scanf("%s %s", comeco, fim) == 2) {
        Posicao comecoPosicao = parsePosicao(comeco);
        Posicao fimPosicao = parsePosicao(fim);
        
        int movimentos = bfs(comecoPosicao, fimPosicao);
        
        printf("To get from %s to %s takes %d knight moves.\n", comeco, fim, movimentos);
    }
    return 0;
}
