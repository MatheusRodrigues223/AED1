// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int T;
    int A, B, C, D, E;
    int certos = 0;

    scanf("%d", &T);
    getchar();

    scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
    getchar();

    if (T == A) certos++;

    if (T == B) certos++;

    if (T == C) certos++;

    if (T == D) certos++;

    if (T == E) certos++;

    printf("%d\n ", certos);



    return 0;
}
