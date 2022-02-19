#include <stdio.h>
#include <string.h>
#include "libs/data_structures/matrix/matrix.h"

int getNorm(matrix m) {
    int norm = abs(m.values[0][0]);

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (abs(m.values[i][j]) > norm)
                norm = abs(m.values[i][j]);

    return norm;
}

void printMatrixWithMinNorm(matrix *ms, int nMatrix) {
    int norms[nMatrix];
    for (int k = 0; k < nMatrix; k++)
        norms[k] = getNorm(ms[k]);

    int max = getMin(norms, nMatrix);

    for (int i = 0; i < nMatrix; i++)
        if (norms[i] == max)
            outputMatrix(ms[i]);
}

int main() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    0, 1, 0,
                    1, 0, 0,
                    0, 0, 0,

                    1, 1, 0,
                    2, 1,0,
                    1, 1,0,

                    0, 0,0,
                    0, 1,0,
                    4, 7,0,

                    1, 0,0,
                    0, 1,0,
                    0, 0,0,

                    0, 1,0,
                    0, 2,0,
                    0, 3,0
            },
            5, 3, 3);

    printMatrixWithMinNorm(ms, 5);
}