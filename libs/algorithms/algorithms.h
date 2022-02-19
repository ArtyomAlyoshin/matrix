#ifndef LAB5D_ALGORITHMS_H
#define LAB5D_ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <math.h>

void swap_(void *a, void *b, size_t size);

void swap(int *a, int *b);

void inputArray(int *a, size_t size);

void outputArray(int *a, size_t size);

int maxElementInRow(int *a, int nCols);

int maxElementInCol(int *a, int nRows);

int minElementInCol(int *a, int nRows);

float getDistance(int *a, int n);

int cmp_long_long(const void *pa, const void *pb);

int countNUnique(long long *a, int n);

long long getSum(int *a, int n);

int getMax(int *a, int n);

#endif //LAB5D_ALGORITHMS_H
