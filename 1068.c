// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void verificar(char input[], char abre, char fecha) {
    int i;
    int tamanho = strlen(input);
    int achou = 0;

    for (i = 0; i < tamanho; i++) {
        if (input[i] == abre) {
            achou++;
        } else if (input[i] == fecha) {
            if (achou > 0) {
                achou--;
            } else {
                printf("incorrect\n");
                return;
            }
        }
    }
    
    if (achou == 0) {
        printf("correct\n");
    } 
    else {
        printf("incorrect\n");
    }
}



int main() {

    int N = 1207;
    char input[1000];

    for (int i = 0; i < N; i++) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        verificar(input, '(', ')');
    }

    return 0;
}
