#include <stdio.h>
#include <string.h>
#include "libs/data_structures/matrix/matrix.h"

bool isNonDescendingSorted(int *a, int n) {
    for (int i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            return false;
    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return false;
    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int count = 0;
    for (int k = 0; k < nMatrix; k++)
        if (hasAllNonDescendingRows(ms[k]))
            count++;

    return count;
}

int main() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    7, 1,
                    1, 1,

                    1, 6,
                    2, 2,

                    5, 4,
                    2, 3,

                    1, 3,
                    7, 9
            },
            4, 2, 2);

    assert(countNonDescendingRowsMatrices(ms, 4) == 2);
}