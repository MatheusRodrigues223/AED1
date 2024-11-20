// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <stdlib.h>

void bubbleSortDecrescente(int lista[], int M) {
    for (int i = 0; i < M - 1; i++) {
        for (int j = 0; j < M - i - 1; j++) {
            if (lista[j] < lista[j + 1]) {
                int temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

int compararListas(int *ordenada, int *desordenada, int tamanho) {
    int igual = 0;

    for (int i = 0; i < tamanho; i++) {
        if (ordenada[i] == desordenada[i]) {
            igual++;
        }
    }

    return igual;
}


int main() {
    int N, M;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &M);

        int* lista = (int*)malloc(M * sizeof(int));
        int* listaDesordenada = (int*)malloc(M * sizeof(int));

        for (int j = 0; j < M; j++) {
            scanf("%d", &lista[j]);
            listaDesordenada[j] = lista[j];
        }

        bubbleSortDecrescente(lista, M);

        printf("%d\n", compararListas(lista, listaDesordenada, M));
        
        free(lista);
        free(listaDesordenada);

    }


    return 0;
}
