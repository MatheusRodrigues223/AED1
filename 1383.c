// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>

#define N 9

int main() {
    int matriz[N][N], n, x, i, j, verificador;

    scanf("%d", &n);
    if (n < 1) {
        return 0;
    }

    for (x = 0; x < n; x++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        verificador = 0;

        for (i = 0; i < N; i++) {
            int linha[N] = {0}, coluna[N] = {0};
            for (j = 0; j < N; j++) {

                if (matriz[i][j] < 1 || matriz[i][j] > 9 || linha[matriz[i][j] - 1]) {
                    verificador = 1;
                    break;
                }
                linha[matriz[i][j] - 1] = 1;

                if (matriz[j][i] < 1 || matriz[j][i] > 9 || coluna[matriz[j][i] - 1]) {
                    verificador = 1;
                    break;
                }
                coluna[matriz[j][i] - 1] = 1;
            }
            if (verificador == 1) break;
        }

        if (verificador == 0) {
            for (int blocoLinha = 0; blocoLinha < 3; blocoLinha++) {
                for (int blocoColuna = 0; blocoColuna < 3; blocoColuna++) {
                    int subgrade[N] = {0};
                    for (i = 0; i < 3; i++) {
                        for (j = 0; j < 3; j++) {
                            int num = matriz[blocoLinha * 3 + i][blocoColuna * 3 + j];
                            if (num < 1 || num > 9 || subgrade[num - 1]) {
                                verificador = 1;
                                break;
                            }
                            subgrade[num - 1] = 1;
                        }
                        if (verificador == 1) break; 
                    }
                    if (verificador == 1) break; 
                }
                if (verificador == 1) break; 
            }
        }


        printf("Instancia %d\n", x + 1);
        if (verificador == 1) {
            printf("NAO\n\n");
        } else {
            printf("SIM\n\n");
        }
    }

    return 0;
}
