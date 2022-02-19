#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

int getNSpecialElement(matrix m) {
    int NSpecial = 0;
    for (int j = 0; j < m.nCols; j++) {
        int specialElement = m.values[0][j];
        int sumOfElementsInCol = 0;
        for (int i = 1; i < m.nRows; i++) {
            if (m.values[i][j] > specialElement) {
                sumOfElementsInCol += specialElement;
                specialElement = m.values[i][j];
            } else
                sumOfElementsInCol += m.values[i][j];
        }
        if (specialElement > sumOfElementsInCol)
            NSpecial++;
    }
    return NSpecial;
}


int main() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 7,
                    12, 2, 1, 2
            },
            3, 4);

    assert(getNSpecialElement(m1) == 2);
}