#include <stdio.h>
#include <string.h>
#include "libs/data_structures/matrix/matrix.h"

int countValues(const int *a, int n, int value) {
    int counter = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == value)
            counter++;

    return counter;
}

int countZeroRows(matrix m) {
    int zeroCounter = 0;
    for (int i = 0; i < m.nRows; i++)
        if (countValues(m.values[i], m.nCols, 0) == m.nCols)
            zeroCounter++;

    return zeroCounter;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int zeroCount[nMatrix];
    for (int k = 0; k < nMatrix; k++)
        zeroCount[k] = countZeroRows(ms[k]);

    int max = getMax(zeroCount, nMatrix);

    for (int i = 0; i < nMatrix; i++)
        if (zeroCount[i] == max)
            outputMatrix(ms[i]);
}

int main() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    0, 1,
                    1, 0,
                    0, 0,

                    1, 1,
                    2, 1,
                    1, 1,

                    0, 0,
                    0, 1,
                    4, 7,

                    2, 0,
                    0, 1,
                    0, 0,

                    0, 1,
                    0, 2,
                    0, 3
            },
            5, 3, 2);

    printMatrixWithMaxZeroRows(ms, 5);
}