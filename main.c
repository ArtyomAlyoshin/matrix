#include <stdio.h>
#include <assert.h>
#include "libs/data_structures/matrix/matrix.h"


void task3(matrix m) {
    insertionSortColsMatrixByColCriteria(m, minElementInCol);
}

int main() {
    matrix m = createMatrixFromArray((int[]) {1, 4, 3,
                                              4, 5, 12,
                                              7, 8, 9}, 3, 3);
    task3(m);
    outputMatrix(m);
    return 0;
}
