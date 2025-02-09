// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

void init_queue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int is_empty(Queue *q) {
    return q->front > q->rear;
}

void enqueue(Queue *q, int value) {
    if (q->rear < MAX - 1) {
        q->items[++q->rear] = value;
    }
}

int dequeue(Queue *q) {
    if (!is_empty(q)) {
        return q->items[q->front++];
    }
    return -1; 
}

int inverter(int num) {
    int invertido = 0;
    while (num > 0) {
        invertido = invertido * 10 + num % 10;
        num /= 10;
    }
    return invertido;
}

int min_operacoes(int inicio, int alvo) {
    Queue q;
    init_queue(&q);
    int visitado[MAX] = {0};
    int distancia[MAX] = {0};

    enqueue(&q, inicio);
    visitado[inicio] = 1;

    while (!is_empty(&q)) {
        int atual = dequeue(&q);

        if (atual == alvo) {
            return distancia[atual];
        }

        int prox1 = atual + 1;
        int prox2 = inverter(atual);

        if (prox1 < MAX && !visitado[prox1]) {
            enqueue(&q, prox1);
            visitado[prox1] = 1;
            distancia[prox1] = distancia[atual] + 1;
        }

        if (prox2 < MAX && !visitado[prox2]) {
            enqueue(&q, prox2);
            visitado[prox2] = 1;
            distancia[prox2] = distancia[atual] + 1;
        }
    }

    return -1;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int a, b;
        scanf("%d %d", &a, &b);

        int resultado = min_operacoes(a, b);
        printf("%d\n", resultado);
    }

    return 0;
}
