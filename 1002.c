// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
 
int main() {
 
    double R, A, n = 3.14159;
    
    scanf("%lf", &R);
    
    R = (int)(R * 100 + 0.5) / 100.0;
    
    A = n * R * R;
    
    printf("A=%.4lf\n", A);
 
    return 0;
}
