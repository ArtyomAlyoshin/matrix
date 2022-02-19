#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

int countEqClassesByRowsSum(matrix m) {
    long long rowSums[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        rowSums[i] = getSum(m.values[i], m.nCols);

    return countNUnique(rowSums, m.nRows);
}


int main() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1,
                    2, 7,
                    5, 4,
                    4, 3,
                    1, 6,
                    8, 0
            },
            6, 2);

    assert(countEqClassesByRowsSum(m1) == 3);
}