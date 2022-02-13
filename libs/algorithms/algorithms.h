#ifndef LAB5D_ALGORITHMS_H
#define LAB5D_ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

void swap_(void *a, void *b, size_t size);
void swap(int *a, int *b);
void inputArray(int *a, size_t size);
void outputArray(int *a, size_t size);
int maxElementInRow(int *a, int nCols);
int maxElementInCol(int *a, int nRows);

#endif //LAB5D_ALGORITHMS_H
