// Matheus da Rosa Rodrigues
// RA: 176614


#include <stdio.h>
#include <stdlib.h>


int encontrarMenorTempo(int *tempos, int N) {
    int minIndex = 0;
    for (int i = 1; i < N; i++) {
        if (tempos[i] < tempos[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int *vi = (int *)malloc(N * sizeof(int));
    int *tempos = (int *)calloc(N, sizeof(int));
    int *cj = (int *)malloc(M * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &vi[i]);
    }

    for (int j = 0; j < M; j++) {
        scanf("%d", &cj[j]);
    }

    for (int j = 0; j < M; j++) {
        int idx = encontrarMenorTempo(tempos, N);
        tempos[idx] += vi[idx] * cj[j];
    }

    int tempoTotal = 0;
    for (int i = 0; i < N; i++) {
        if (tempos[i] > tempoTotal) {
            tempoTotal = tempos[i];
        }
    }

    printf("%d\n", tempoTotal);

    free(vi);
    free(cj);
    free(tempos);

    return 0;
}
