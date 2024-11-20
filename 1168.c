// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
 
int main() {
    int N;
    int leds;
    char numero[1001];
    int j;
    
    scanf("%d", &N);
    getchar();
    
    
    
    for (int i = 0; i < N; i++) {
        
        scanf("%s", &numero);
        getchar();
        
        leds = 0;
        j = 0;
        
        while (numero[j] != '\0') {
        
            if (numero[j] == '1') leds += 2;
            if (numero[j] == '2') leds += 5;
            if (numero[j] == '3') leds += 5;
            if (numero[j] == '4') leds += 4;
            if (numero[j] == '5') leds += 5;
            if (numero[j] == '6') leds += 6;
            if (numero[j] == '7') leds += 3;
            if (numero[j] == '8') leds += 7;
            if (numero[j] == '9') leds += 6;
            if (numero[j] == '0') leds += 6;
        
            j++;
        
        } 
        
        printf("%d leds\n", leds);
    }
    
    return 0;
}

