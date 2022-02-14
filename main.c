#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

matrix task4(matrix m) {
    if (isSymmetricMatrix(m)) {
        return mulMatrices(m, m);
    } else
        return m;
}

int main() {
    matrix m1 = createMatrixFromArray((int[]) {7, 4, 7,
                                               4, 18, 1,
                                               7, 1, 9
    }, 3, 3);

    matrix m2 = task4(m1);
    outputMatrix(m2);
    return 0;
}