// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
 
int main() {
    int N, S;
    int dia;
    
    scanf("%d %d", &N, &S);
    getchar();
    
    int menor = S;
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &dia);
        getchar();
        
        S += dia;
        
        if (S < menor) {
            menor = S;
        }
    }
    
    printf("%d\n", menor);
    
 
    return 0;
}
