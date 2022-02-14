#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    return isEMatrix(mulMatrices(m1, m2));
}

int main() {
    matrix m1 = createMatrixFromArray((int[]) {2, 5, 7,
                                               6, 3, 4,
                                               5, -2, -3}, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, -1, 1,
                                               -38, 41, -34,
                                               27, -29, 24}, 3, 3);

    printf("%d", isMutuallyInverseMatrices(m1, m2));

    return 0;
}
