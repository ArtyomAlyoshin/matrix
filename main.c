#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

int max2(int a, int b) {
    return a > b ? a : b;
}

int getSum(int *a, int size) {
    int sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += a[i];
    }
    return sum;
}

int findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int sumArray[m.nCols + m.nRows - 2];
    int k = 0;
    for (size_t i = 1, j = 0; i < m.nRows; i++, j++) {
        int max = m.values[i][0];
        int duplicate = i;
        while (i + 1 < m.nRows && j + 1 < m.nCols) {
            j++;
            i++;
            max = max2(max, m.values[i][j]);
        }
        sumArray[k++] = max;
        j = 0;
        i = duplicate;
    }
    for (size_t i = 1, j = 0; i < m.nCols; i++, j++) {
        int max = m.values[0][i];
        int duplicate = i;
        while (i + 1 < m.nCols && j + 1 < m.nRows) {
            j++;
            i++;
            max = max2(max, m.values[j][i]);
        }
        sumArray[k++] = max;
        j = 0;
        i = duplicate;
    }
    int sum = getSum(sumArray, m.nRows + m.nCols - 2);
    return sum;
}


int main() {
    matrix m1 = createMatrixFromArray((int[]) {3, 2, 5, 4,
                                               5, 3, 6, 3,
                                               3, 2, 1, 2}, 3, 4);

    printf("%d", findSumOfMaxesOfPseudoDiagonal(m1));
    return 0;
}
