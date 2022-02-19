#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}


int main() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    8, 9, 10, 11,
                    0, 1, 2, 3,
                    4, 5, 6, 7
            },
            3, 4);

    sortByDistances(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    0, 1, 2, 3,
                    4, 5, 6, 7,
                    8, 9, 10, 11,
            },
            3, 4);

    assert(twoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}