// Matheus da Rosa Rodrigues
// RA: 176614


#include <stdio.h>
#include <string.h>

int main() {
    int N;
    float L, Q;
    char nomes[10][13];

    scanf("%d %f %f", &N, &L, &Q);
    for (int i = 0; i < N; i++) {
        scanf("%s", nomes[i]);
    }

    int indiceRico = 0;
    float ultimaCuia = 0.0;

    int i = 0;
    while (L > 0) {
        if (L >= Q) {
            L -= Q;
            ultimaCuia = Q;
        } else {
            ultimaCuia = L;
            L = 0;
        }
        indiceRico = i;
        i = (i + 1) % N;
    }
    
    printf("%s %.1f\n", nomes[indiceRico], ultimaCuia);
    return 0;
}
