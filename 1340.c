// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

typedef struct {
    int value[1000];
    int topo;
} Pilha;

typedef struct {
    int value[MAX];
    int frente, tras;
} Fila;

typedef struct {
    int value[MAX];
    int topo;
} Prioridade;

void iniciaPilha(Pilha *pilha) {
    pilha->topo = -1;
}

bool inserePilha(Pilha *pilha, int x) {
    if (pilha->topo >= MAX - 1) return false;
    pilha->value[++pilha->topo] = x;
    return true;
}

bool removePilha(Pilha *pilha, int *x) {
    if (pilha->topo < 0) return false;
    *x = pilha->value[pilha->topo--];
    return true;
}

void iniciaFila(Fila *fila) {
    fila->frente = 0;
    fila->tras = 0;
}

bool insereFila(Fila *fila, int x) {
    if (fila->tras >= MAX) return false;
    fila->value[fila->tras++] = x;
    return true;
}

bool removeFila(Fila *fila, int *x) {
    if (fila->frente == fila->tras) return false;
    *x = fila->value[fila->frente++];
    return true;
}

void iniciaPrioridade(Prioridade *prioridade) {
    prioridade->topo = 0;
}

bool inserePrioridade(Prioridade *prioridade, int x) {
    if (prioridade->topo == MAX) return false;
    prioridade->value[prioridade->topo++] = x;
    return true;
}

bool removePrioridade(Prioridade *prioridade, int *x) {
    if (prioridade->topo == 0) return false;
    int maximo = 0;
    for (int i = 0; i < prioridade->topo; i++) {
        if (prioridade->value[i] > prioridade->value[maximo]) {
            maximo = i;
        }
    }
    *x = prioridade->value[maximo];
    prioridade->value[maximo] = prioridade->value[--prioridade->topo];
    return true;
}

int main() {
    int n, j = 0;
    int *resultados = malloc(sizeof(int) * 10000);

    while (scanf("%d", &n) != EOF) {
        Pilha pilha;
        Fila fila;
        Prioridade prioridade;

        iniciaPilha(&pilha);
        iniciaFila(&fila);
        iniciaPrioridade(&prioridade);

        bool isPilha = true, isFila = true, isPrioridade = true;

        for (int i = 0; i < n; i++) {
            int cmd, x;
            scanf("%d %d", &cmd, &x);

            if (cmd == 1) {
                if (isPilha) inserePilha(&pilha, x);
                if (isFila) insereFila(&fila, x);
                if (isPrioridade) inserePrioridade(&prioridade, x);
            } else if (cmd == 2) {
                int val;
                if (isPilha) {
                    if (!removePilha(&pilha, &val) || val != x) isPilha = false;
                }
                if (isFila) {
                    if (!removeFila(&fila, &val) || val != x) isFila = false;
                }
                if (isPrioridade) {
                    if (!removePrioridade(&prioridade, &val) || val != x) isPrioridade = false;
                }
            }
        }

        if (isPilha + isFila + isPrioridade > 1) {
            resultados[j] = 0;
        } else if (isPilha) {
            resultados[j] = 1;
        } else if (isFila) {
            resultados[j] = 2;
        } else if (isPrioridade) {
            resultados[j] = 3;
        } else {
            resultados[j] = 4;
        }
        j++;
    }

    for (int i = 0; i < j; i++) {
        if (resultados[i] == 0)
            printf("not sure\n");
        else if (resultados[i] == 1)
            printf("stack\n");
        else if (resultados[i] == 2)
            printf("queue\n");
        else if (resultados[i] == 3)
            printf("priority queue\n");
        else
            printf("impossible\n");
    }

    free(resultados);
    return 0;
}
