#include <stdio.h>
#include <assert.h>
#include "libs/data_structures/matrix/matrix.h"

//функция MAX написана в файле algorithms.c
void task2(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, maxElementInRow);
}

int main() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 12,
                                              7, 8, 9}, 3, 3);
    task2(m);
    outputMatrix(m);
    return 0;
}
