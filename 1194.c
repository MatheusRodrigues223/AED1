// Matheus da Rosa Rodrigues
// RA: 176614


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char dado;
    struct No* esq;
    struct No* dir;
} No;

No* novoNo(char dado) {
    No* no = (No*)malloc(sizeof(No));
    no -> dado = dado;
    no -> esq = no -> dir = NULL;
    return no;
}

int encontrarIndex(char* string, char dado, int comeco, int fim) {
    for (int i = comeco; i <= fim; i++) {
        if (string[i] == dado) {
            return i;
        }
    }
    return -1;
}

No* construirArvore(char* prefixo, char* infixo, int infixoComeco, int infixoFim, int *prefixoIndex) {
    if (infixoComeco > infixoFim) {
        return NULL;
    }
    
    char atual = prefixo[*prefixoIndex];
    (*prefixoIndex)++;
    No* no = novoNo(atual);
    
    if (infixoComeco ==  infixoFim) {
        return no;
    }
    
    int infixoIndex = encontrarIndex(infixo, atual, infixoComeco, infixoFim);
    
    no -> esq = construirArvore(prefixo, infixo, infixoComeco, infixoIndex - 1, prefixoIndex);
    no -> dir = construirArvore(prefixo, infixo, infixoIndex + 1, infixoFim, prefixoIndex);

    return no;
}

void posfixar(No* no) {
    if (no == NULL) {
        return;
    }
    
    posfixar(no -> esq);
    posfixar(no -> dir);
    printf("%c", no -> dado);
}

void liberarArvore(No* no) {
    if (no == NULL) {
        return;
    }
    
    liberarArvore(no -> esq);
    liberarArvore(no -> dir);
    free(no);
}

 
int main() {
    int C, N;
    scanf("%d", &C);
    
    for (int i = 0; i < C; i++) {
        char prefixo[53], infixo[53];
        
        scanf("%d %s %s", &N, &prefixo, &infixo);
        
        int prefixoIndex = 0;
        No* raiz = construirArvore(prefixo, infixo, 0, N - 1, &prefixoIndex);
        
        posfixar(raiz);
        printf("\n");
        
        liberarArvore(raiz);
    }
    return 0;
}
