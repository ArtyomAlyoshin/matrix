#include <stdio.h>
#include <string.h>
#include "libs/data_structures/matrix/matrix.h"

position getLeftMin(matrix m) {
    int min = m.values[0][0];
    position minPosition = {0, 0};

    for (int j = 0; j < m.nCols; j++)
        for (int i = 0; i < m.nRows; i++)
            if (m.values[i][j] < min) {
                min = m.values[i][j];
                minPosition.colIndex = j;
                minPosition.rowIndex = i;
            }

    return minPosition;
}

void swapPenultimateRow(matrix m) {
    if (m.nRows < 2) {
        printf("bad case");
    }

    int col[m.nRows];
    position min = getLeftMin(m);

    for (int i = 0; i < m.nRows; i++)
        col[i] = m.values[i][min.colIndex];

    memcpy(m.values[m.nRows - 2], col, sizeof(int) * m.nCols);
}

int main() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 1,
            },
            3, 3);

    swapPenultimateRow(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    1, 4, 7,
                    7, 8, 1,
            },
            3, 3);

    assert(twoMatricesEqual(m1, m2));
}