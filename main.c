#include <stdio.h>
#include <string.h>
#include "libs/data_structures/matrix/matrix.h"



//исправление 6 задания
bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix mulMatrix = mulMatrices(m1, m2);
    bool EMatrix = isEMatrix(mulMatrix);
    freeMemMatrix(mulMatrix);
    return EMatrix;
}

int max2(int a, int b) {
    return a > b ? a : b;
}

//упрощена задача 7
long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int size = m.nRows + m.nCols - 1;
    int sumArray[size];
    for (int i = 0; i < size; ++i) {
        sumArray[i] = 0;
    }

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (j != i) {
                int numberOfPsevdoDiagonals = j - i + 2;
                sumArray[numberOfPsevdoDiagonals] = max2(sumArray[numberOfPsevdoDiagonals], m.values[i][j]);
            }

    return getSum(sumArray, size);
}


int main() {
    matrix m1 = createMatrixFromArray((int[]) {3, 2, 5, 4,
                                               1, 3, 6, 3,
                                               3, 2, 1, 2}, 3, 4);

    printf("%d", findSumOfMaxesOfPseudoDiagonal(m1));
    return 0;
}