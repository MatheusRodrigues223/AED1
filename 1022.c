// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <stdlib.h>

typedef struct Eq {
    int numerador;
    int denominador;
    struct Eq* prox;
} Eq;

Eq* calcular(Eq* novaEq) {
    int N1, N2, D1, D2;
    char operador;
    scanf("%d / %d %c %d / %d", &N1, &D1, &operador, &N2, &D2);
    
    switch (operador) {
        case '+':
            novaEq->numerador = (N1 * D2) + (N2 * D1);
            novaEq->denominador = D1 * D2;
            break;
        case '-':
            novaEq->numerador = (N1 * D2) - (N2 * D1);
            novaEq->denominador = D1 * D2;
            break;
        case '*':
            novaEq->numerador = N1 * N2;
            novaEq->denominador = D1 * D2;
            break;
        case '/':
            novaEq->numerador = N1 * D2;
            novaEq->denominador = N2 * D1;
            break;
    }
    
    return novaEq;
}

Eq* criarEq() {
    Eq* novaEq = (Eq*)malloc(sizeof(Eq));
    novaEq->prox = NULL;
    return calcular(novaEq);
}

void inserirEq(Eq** cabeca) {
    Eq* novaEq = criarEq();
    if (*cabeca == NULL) {
        *cabeca = novaEq;
        return;
    }

    Eq* temp = *cabeca;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = novaEq;
}

int calcularMdc(int n, int m) {
    while (n != 0) {
        int resto = m % n;
        m = n;
        n = resto;
    }
    return (m < 0) ? -m : m;
}

void imprimirFila(Eq* cabeca) {
    Eq* temp = cabeca;
    while (temp != NULL) {
        printf("%d/%d", temp->numerador, temp->denominador);
        int mdc = calcularMdc(temp->numerador, temp->denominador);
        if (mdc != 0) {
            printf(" = %d/%d", temp->numerador / mdc, temp->denominador / mdc);
        }
        printf("\n");
        temp = temp->prox;
    }
}

int main() {
    int numEquacoes;
    Eq* cabeca = NULL;

    scanf("%d", &numEquacoes);

    for (int i = 0; i < numEquacoes; i++) {
        inserirEq(&cabeca);
    }
    
    imprimirFila(cabeca);
    free(cabeca);
    return 0;
}
