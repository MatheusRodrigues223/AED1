// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Celula {
    char nome[21];
    struct Celula* proximo;
} Celula;

Celula* criarCelula(char* nome) {
    Celula* novaCelula = (Celula*)malloc(sizeof(Celula));
    strcpy(novaCelula -> nome, nome);
    novaCelula -> proximo = NULL;
    return novaCelula;
}

void inserirCelula(Celula** cabeca, char* nome) {
    Celula* atual = *cabeca;
    Celula* anterior = NULL;

    while (atual != NULL && strcmp(atual -> nome, nome) < 0) {
        anterior = atual;
        atual = atual -> proximo;
    }

    Celula* novaCelula = criarCelula(nome);

    if (anterior == NULL) {
        novaCelula -> proximo = *cabeca;
        *cabeca = novaCelula;
    }
    else {
        novaCelula -> proximo = atual;
        anterior -> proximo = novaCelula;
    }
}

char* buscarElemento(Celula* cabeca, int index) {
    Celula* temp = cabeca;

    for (int i = 0; i < index - 1; i++) {
        temp = temp -> proximo;
    }

    return temp -> nome;
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
    int N, K;
    char nome[21];

    scanf("%d %d", &N, &K);

    Celula* nomes = NULL;

    for (int i = 0; i < N; i++) {
        scanf("%s", nome);

        inserirCelula(&nomes, nome);
    }

    char* nomeEncontrado = buscarElemento(nomes, K);

    printf("%s\n", nomeEncontrado);

    limpar(nomes);

    return 0;
}
