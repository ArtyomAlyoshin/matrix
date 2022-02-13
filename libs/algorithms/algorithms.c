
#include "algorithms.h"

void inputArray(int *a, size_t size) {
    for (size_t i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
}

void outputArray(int *a, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void swap_(void *a, void *b, size_t size) {
    char *pa = a;
    char *pb = b;
    for (size_t i = 0; i < size; i++) {
        char t = *pa;
        *pa = *pb;
        *pb = t;
        pa++;
        pb++;
    }
}

int maxElementInRow(int *a, int nCols) {
    int max = a[0];
    for (int i = 0; i < nCols; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int maxElementInCol(int *a, int nRows) {
    int max = a[0];
    for (int i = 0; i < nRows; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}