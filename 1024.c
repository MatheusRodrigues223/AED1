// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <string.h>

void criptografar(char* texto) {
    int len = strlen(texto);
    
    for (int i = 0; i < len; i++) {
        if ((texto[i] >= 'a' && texto[i] <= 'z') || (texto[i] >= 'A' && texto[i] <= 'Z')) {
            texto[i] += 3;
        }
    }

    for (int i = 0; i < len / 2; i++) {
        char temp = texto[i];
        texto[i] = texto[len - i - 1];
        texto[len - i - 1] = temp;
    }

    int meio = len / 2;
    for (int i = meio; i < len; i++) {
        texto[i] -= 1;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        char linha[1001];
        fgets(linha, 1001, stdin);
        
        if (linha[strlen(linha) - 1] == '\n') {
            linha[strlen(linha) - 1] = '\0';
        }

        criptografar(linha);
        printf("%s\n", linha);
    }

    return 0;
}
