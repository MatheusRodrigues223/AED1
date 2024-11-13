// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Celula {
    char nome[20];
    struct Celula* proximo;
} Celula;

Celula* criarCelula(char* nome) {
    Celula* novaCelula = (Celula*)malloc(sizeof(Celula));
    strcpy(novaCelula -> nome, nome);
    novaCelula -> proximo = NULL;
    return novaCelula;  
}

void inserirCelula(Celula** cabeca, char* nome, char* condicao) {
    Celula* novaCelula = criarCelula(nome);

    if (*cabeca == NULL) {
        *cabeca = novaCelula;
        return;
    }

    Celula* temp = NULL;
    Celula* ultima = *cabeca;

    if (condicao == NULL || strcmp(condicao, "nao") == 0 || strlen(condicao) == 0) {
        while (ultima -> proximo != NULL) {
            ultima = ultima -> proximo;
        }
        ultima -> proximo = novaCelula;
    }
    else {
        while (ultima != NULL && strcmp(ultima -> nome, condicao) != 0) {
            temp = ultima;
            ultima = ultima -> proximo;
        }

        if (ultima == NULL) {
            temp -> proximo = novaCelula;
        }
        else if (temp == NULL) {
            novaCelula -> proximo = *cabeca;
            *cabeca = novaCelula;
        }
        else {
            novaCelula -> proximo = ultima;
            temp -> proximo = novaCelula;
        }   
    }

}

void imprimirLista(Celula* cabeca) {
    Celula* temp = cabeca;
    while (temp != NULL) {
        printf("%s", temp -> nome);
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
    char *amigos;
    char *condicao = NULL;
    char* token;
    
    Celula* cabecaAmigos = NULL;

    for (int i = 0; i < 2; i++) {
        amigos = (char*)calloc(100, sizeof(char));
        fgets(amigos, 100, stdin);

        if (i == 1) {
            condicao = (char*)calloc(15, sizeof(char));
            fgets(condicao, 15, stdin);
            condicao[strcspn(condicao, "\n")] = '\0';
        }
        
        token = strtok(amigos, " \n");
        while (token != NULL) {
            inserirCelula(&cabecaAmigos, token, condicao);
            token = strtok(NULL, " \n");
        }

        free(amigos);
    }

    free(condicao);
    imprimirLista(cabecaAmigos);
    limpar(cabecaAmigos);

    return 0;
}
