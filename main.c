#include <stdio.h>
#include <assert.h>
#include "libs/data_structures/matrix/matrix.h"

void task1(matrix m) {
    position maxIndex = getMaxValuePos(m);
    position minIndex = getMinValuePos(m);
    swapRows(m, maxIndex.rowIndex, minIndex.rowIndex);
}

int main() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    task1(m);
    outputMatrix(m);
    return 0;
}
