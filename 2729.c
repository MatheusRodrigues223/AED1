// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Celula {
    char palavra[21];
    struct Celula *proximo;
} Celula; 

Celula* criarCelula(char* palavra) {
    Celula* novaCelula = (Celula*)malloc(sizeof(Celula));
    strcpy(novaCelula -> palavra, palavra);
    novaCelula -> proximo = NULL;
    return novaCelula;
}

void inserirCelula(Celula** cabeca, char* palavra) {
    Celula* atual = *cabeca;
    Celula* anterior = NULL;

    while (atual != NULL && strcmp(atual -> palavra, palavra) < 0) {
        anterior = atual;
        atual = atual -> proximo;
    }

    if (atual != NULL && strcmp(atual -> palavra, palavra) == 0) {
        return;
    }

    Celula* novaCelula = criarCelula(palavra);
    if (novaCelula == NULL) {
        return;
    }

    if (anterior == NULL) {
        novaCelula -> proximo = *cabeca;
        *cabeca = novaCelula;
    }    
    else {
        novaCelula -> proximo = atual;
        anterior -> proximo = novaCelula;
    }

}

void imprimirLista(Celula* cabeca) {
    Celula* temp = cabeca;
    while (temp != NULL) {
        printf("%s", temp -> palavra);
        temp = temp -> proximo;
        if (temp != NULL) {
            printf(" ");
        }
    }
    printf("\n");
}

void limpar(Celula* cabeca) {
    Celula* temp;
    while (cabeca != NULL) {
        temp = cabeca;
        cabeca = cabeca -> proximo;
        free(temp);
    }
}



int main() {

    int N;
    scanf("%d", &N);
    getchar();

    Celula** listas = (Celula**)malloc(N * sizeof(Celula*));
    for (int i = 0; i < N; i++) {
        listas[i] = NULL;
    }

    for (int i = 0; i < N; i++) {
        char* palavras = (char*)calloc(21001, sizeof(char));

        fgets(palavras, 21001, stdin);
        palavras[strcspn(palavras, "\n")] = 0;

        char* palavra = strtok(palavras, " ");
        while (palavra != NULL) {
            inserirCelula(&listas[i], palavra);
            palavra = strtok(NULL, " ");
        }

        free(palavras);
    }

    for (int i = 0; i < N; i++) {
        imprimirLista(listas[i]);
        limpar(listas[i]);
    }

    free(listas);

    return 0;
}
