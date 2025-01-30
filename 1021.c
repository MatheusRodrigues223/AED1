// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>

int main() {
    double valor;
    int notas, moedas;

    int valor_notas[] = {100, 50, 20, 10, 5, 2};
    double valor_moedas[] = {1.00, 0.50, 0.25, 0.10, 0.05, 0.01};

    scanf("%lf", &valor);

    printf("NOTAS:\n");
    for (int i = 0; i < 6; i++) {
        notas = (int)valor / valor_notas[i];
        printf("%d nota(s) de R$ %.2f\n", notas, (double)valor_notas[i]);
        valor -= notas * valor_notas[i];
    }

    printf("MOEDAS:\n");
    valor = valor + 0.001;
    for (int i = 0; i < 6; i++) {
        moedas = (int)(valor / valor_moedas[i]);
        printf("%d moeda(s) de R$ %.2f\n", moedas, valor_moedas[i]);
        valor -= moedas * valor_moedas[i];
    }

    return 0;
}
