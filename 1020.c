// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
 
int main() 
{
    int dias, anos, meses, resto;

    scanf("%d", &dias);

    anos = dias / 365; 
    resto = dias % 365; 

    meses = resto / 30; 
    resto = resto % 30; 

    
    printf("%d ano(s)\n", anos);
    printf("%d mes(es)\n", meses);
    printf("%d dia(s)\n", resto);

    return 0;
