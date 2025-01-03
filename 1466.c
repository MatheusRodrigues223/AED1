// Matheus da Rosa Rodrigues
// RA: 176614



#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  int dado;
  struct No* esq;
  struct No* dir;
} No;

No* novoNo(int dado) {
  No* no = (No*)malloc(sizeof(No));
  no -> dado = dado;
  no -> esq = no -> dir = NULL;
  return no;
}

No* inserirNo(No* raiz, int dado) {
  if (raiz == NULL) {
    return novoNo(dado);
  }
  if (dado < raiz -> dado) {
     raiz -> esq = inserirNo(raiz -> esq, dado);
  } else if (dado > raiz -> dado) {
    raiz -> dir = inserirNo(raiz -> dir, dado);
  }

  return raiz;
}

typedef struct Fila {
  No* no;
  struct Fila* prox;
} Fila;

Fila* novaFila(No* no) {
  Fila* fila = (Fila*)malloc(sizeof(Fila));
  fila -> no = no;
  fila -> prox = NULL;
  return fila;
}

void enfileirar(Fila** frente, Fila** traseira, No* no) {
  Fila* temp = novaFila(no);
  if (*traseira == NULL) {
    *frente = *traseira = temp;
    return;
  }

  (*traseira) -> prox = temp;
  *traseira = temp;
}

No* desenfileirar(Fila** frente, Fila** traseira) {
  if (*frente == NULL) {
    return NULL;
  }

  Fila* temp = *frente;
  No* no = temp -> no;
  *frente = (*frente) -> prox;
  if (*frente == NULL) {
    *traseira = NULL;
  }
  free(temp);
  return no;
}

int filaVazia(Fila* frente) {
  return frente == NULL;
}

void percorrerPorNivel(No* raiz) {
  if (raiz == NULL) {
     return;
  }

  Fila* frente = NULL;
  Fila* traseira = NULL;
  enfileirar(&frente, &traseira, raiz);
  int primeiro = 1;

  while (!filaVazia(frente)) {
    No* no = desenfileirar(&frente, &traseira);
    if (!primeiro) {
      printf(" ");
    }

    printf("%d", no -> dado);
    primeiro = 0;
    if (no -> esq != NULL) {
      enfileirar(&frente, &traseira, no -> esq);
    }
    if (no -> dir != NULL) {
      enfileirar(&frente, &traseira, no -> dir);
    }
  }
  printf("\n");
}



 
int main() {
    int C, N;
    
    scanf("%d", &C);
    
    for (int caso = 1; caso <= C; caso++) {
        scanf("%d", &N);
        
        No* raiz = NULL;
        int valor;
      
        for (int i = 0; i < N; i++) {
          scanf("%d", &valor);
          raiz = inserirNo(raiz, valor);
        }

      printf("Case %d:\n", caso);
      percorrerPorNivel(raiz);
      printf("\n");
    }
    return 0;
}
