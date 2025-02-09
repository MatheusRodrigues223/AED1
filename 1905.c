// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <stdbool.h>

#define TAMANHO 5

int deslocamento_x[] = {-1, 1, 0, 0};
int deslocamento_y[] = {0, 0, -1, 1};


bool posicao_valida(int x, int y, int labirinto[TAMANHO][TAMANHO], bool visitado[TAMANHO][TAMANHO]) {
    return x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO && labirinto[x][y] == 0 && !visitado[x][y];
}

bool busca_largura(int labirinto[TAMANHO][TAMANHO]) {
    bool visitado[TAMANHO][TAMANHO] = {false};
    int fila[TAMANHO * TAMANHO][2];
    int frente = 0, tras = 0;
    

    fila[tras][0] = 0;
    fila[tras][1] = 0;
    tras++;
    visitado[0][0] = true;
    
    while (frente < tras) {
        int x = fila[frente][0];
        int y = fila[frente][1];
        frente++;
        

        if (x == TAMANHO - 1 && y == TAMANHO - 1) return true;
        
        for (int i = 0; i < 4; i++) {
            int novo_x = x + deslocamento_x[i];
            int novo_y = y + deslocamento_y[i];
            
            if (posicao_valida(novo_x, novo_y, labirinto, visitado)) {
                fila[tras][0] = novo_x;
                fila[tras][1] = novo_y;
                tras++;
                visitado[novo_x][novo_y] = true;
            }
        }
    }
    return false;
}

int main() {
    int casos_teste;
    scanf("%d", &casos_teste);
    
    while (casos_teste--) {
        int labirinto[TAMANHO][TAMANHO];
        for (int i = 0; i < TAMANHO; i++) {
            for (int j = 0; j < TAMANHO; j++) {
                scanf("%d", &labirinto[i][j]);
            }
        }
        
        if (busca_largura(labirinto)) {
            printf("COPS\n");
        } else {
            printf("ROBBERS\n");
        }
    }
    
    return 0;
}

