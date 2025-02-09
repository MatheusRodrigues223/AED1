// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, q, caso = 1;

    while (scanf("%d %d", &n, &q), n != 0 && q != 0) {
        int *marmores = (int *)malloc(n * sizeof(int));
        int *consultas = (int *)malloc(q * sizeof(int));

        for (int i = 0; i < n; i++) {
            scanf("%d", &marmores[i]);
        }

        for (int i = 0; i < q; i++) {
            scanf("%d", &consultas[i]);
        }

        qsort(marmores, n, sizeof(int), compare);

        printf("CASE# %d:\n", caso++);

        for (int i = 0; i < q; i++) {
            int x = consultas[i];
            int low = 0, high = n - 1, mid;
            int found = 0;
            
            while (low <= high) {
                mid = (low + high) / 2;
                if (marmores[mid] == x) {
                    found = 1;
                    while (mid > 0 && marmores[mid - 1] == x) {
                        mid--;
                    }
                    printf("%d found at %d\n", x, mid + 1);
                    break;
                } else if (marmores[mid] < x) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            
            if (!found) {
                printf("%d not found\n", x);
            }
        }

        free(marmores);
        free(consultas);
    }

    return 0;
}
