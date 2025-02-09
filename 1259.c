// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <stdlib.h>

int compare_asc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int compare_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int n;
    scanf("%d", &n);

    int pares[100000], impares[100000];
    int num, p_count = 0, i_count = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (num % 2 == 0) {
            pares[p_count++] = num;
        } else {
            impares[i_count++] = num;
        }
    }

    qsort(pares, p_count, sizeof(int), compare_asc);
    qsort(impares, i_count, sizeof(int), compare_desc);

    for (int i = 0; i < p_count; i++) {
        printf("%d\n", pares[i]);
    }
    for (int i = 0; i < i_count; i++) {
        printf("%d\n", impares[i]);
    }

    return 0;
}
