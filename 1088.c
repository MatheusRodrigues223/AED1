// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <stdlib.h>

int merge_and_count(int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    int inv_count = 0;

    i = left;    // Índice para a submatriz esquerda
    j = mid;     // Índice para a submatriz direita
    k = left;    // Índice para a submatriz de saída temporária

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];

            // Há inversões, pois todos os elementos restantes na submatriz esquerda
            // (arr[i...mid-1]) são maiores que arr[j]
            inv_count += (mid - i);
        }
    }

    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

int merge_sort_and_count(int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;

        inv_count += merge_sort_and_count(arr, temp, left, mid);
        inv_count += merge_sort_and_count(arr, temp, mid + 1, right);

        inv_count += merge_and_count(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

int main() {
    int n;

    while (scanf("%d", &n), n != 0) {
        int *arr = (int *)malloc(n * sizeof(int));
        int *temp = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int inversions = merge_sort_and_count(arr, temp, 0, n - 1);

        if (inversions % 2 == 0) {
            printf("Carlos\n");
        } else {
            printf("Marcelo\n");
        }

        free(arr);
        free(temp);
    }

    return 0;
}
