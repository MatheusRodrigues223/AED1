// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int X, Y;

void andar(char matriz[][100], bool visitado[][100], int x, int y) {
    if (x < 0 || x >= X || y < 0 || y >= Y || visitado[y][x]) {
        printf("!\n");
        return;
    }

    visitado[y][x] = true;

    if (matriz[y][x] == '>') {
        while (x + 1 < X && matriz[y][x + 1] == '.') {
            x++;
        }
        andar(matriz, visitado, x + 1, y);
    } else if (matriz[y][x] == '<') {
        while (x - 1 >= 0 && matriz[y][x - 1] == '.') {
            x--;
        }
        andar(matriz, visitado, x - 1, y);
    } else if (matriz[y][x] == 'v') {
        while (y + 1 < Y && matriz[y + 1][x] == '.') {
            y++;
        }
        andar(matriz, visitado, x, y + 1);
    } else if (matriz[y][x] == '^') {
        while (y - 1 >= 0 && matriz[y - 1][x] == '.') {
            y--;
        }
        andar(matriz, visitado, x, y - 1);
    } else if (matriz[y][x] == '*') {
        printf("*\n");
    } else {
        printf("!\n");
    }
}

int main() {
    scanf("%d", &X);
    scanf("%d", &Y);

    char matriz[100][100];
    bool visitado[100][100] = {false};

    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            scanf(" %c", &matriz[i][j]);
        }
    }

    andar(matriz, visitado, 0, 0);

    return 0;
}
