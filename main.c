#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

long long getSum(int *a, int size) {
    int sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += a[i];
    }
    return sum;
}

bool isUnique(long long *a, int size) {
    for (size_t i = 1; i < size; ++i) {
        if (a[i - 1] == a[i])
            return false;
    }
    return true;
}

matrix task5(matrix m) {
    int arrayOfSum[m.nRows];
    for (size_t i = 0; i < m.nRows; ++i) {
        arrayOfSum[i] = getSum(m.values[i], m.nCols);
    }
    if (isUnique(arrayOfSum, m.nRows))
        transposeSquareMatrix(m);
    return m;

}

int main() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9
    }, 3, 3);

    m = task5(m);
    outputMatrix(m);
    return 0;
}