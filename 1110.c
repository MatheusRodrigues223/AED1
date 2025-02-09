// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>

int main() {
    int n;

    while (scanf("%d", &n), n != 0) {
        int cartas[100], descartadas[100];
        int topo = 0, base = 0, d_topo = 0;

        for (int i = 1; i <= n; i++) {
            cartas[base++] = i;
        }

        while (base - topo > 1) {
            descartadas[d_topo++] = cartas[topo++];
            cartas[base++] = cartas[topo++];
        }

        printf("Discarded cards:");
        if (d_topo > 0) {
            printf(" %d", descartadas[0]);
        }
        for (int i = 1; i < d_topo; i++) {
            printf(", %d", descartadas[i]);
        }

        printf("\nRemaining card: %d\n", cartas[topo]);
    }

    return 0;
}
