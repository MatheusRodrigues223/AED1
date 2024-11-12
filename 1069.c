// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void limpar(char input[], char areia) {
    int i, j = 0;
    int tamanho = strlen(input);
    for (i = 0; i < tamanho; i++) {
        if (input[i] != areia) {
            input[j++] = input[i];
        }
    }
    input[j] = '\0';
}

int acharDiamantes(char input[]) {
    int i, j;
    int diamantes = 0;
    int tamanho = strlen(input);

    while(1) {
        int achou = 0;
        for (i = 0; i < tamanho - 1; i++) {
            if (input[i] == '<' && input[i + 1] == '>') {
                diamantes++;
                achou = 1;
                for (j = i; j < tamanho - 2; j++) {
                    input[j] = input[j + 2];
                }
                input[tamanho - 2] = '\0';
                input[tamanho - 1] = '\0';
                tamanho -= 2;
                break;
            }
        } 

        if (!achou) {
            break;
        }
    }

    return diamantes;
}

int main() {

    int N;
    char input[1000];

    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        limpar(input, '.');
        int diamantes = acharDiamantes(input);
        printf("%d\n", diamantes);

    }



    return 0;
}
