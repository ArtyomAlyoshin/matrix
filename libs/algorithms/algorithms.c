
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

int minElementInCol(int *a, int nRows) {
    int min = a[0];
    for (int i = 0; i < nRows; i++) {
        if (a[i] <= min) {
            min = a[i];
        }
    }
    return min;
}

float getDistance(int *a, int n) {
    float distance = 0;
    for (int i = 0; i < n; i++)
        distance += (float) (a[i] * a[i]);

    return sqrtf(distance);
}

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;

    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}

int countNUnique(long long *a, int n) {
    if (n == 1)
        return 1;

    qsort(a, n, sizeof(long long), cmp_long_long);

    int counterOfUnique = 1;
    int i = 1;
    while (i < n) {
        if (a[i] != a[i - 1])
            counterOfUnique++;
        i++;
    }

    return counterOfUnique;
}

long long getSum(int *a, int n) {
    long long sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += a[i];
    return sum;
}