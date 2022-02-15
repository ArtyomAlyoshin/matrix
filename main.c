#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

int min2(int a, int b) {
    return a < b ? a : b;
}

int getMinInArea(matrix m) {
    position p = getMaxValuePos(m);
    int min = m.values[p.rowIndex][p.colIndex];
    int left = p.colIndex;
    int right = p.rowIndex;
    for (int i = p.rowIndex - 1; i >= 0; i--) {
        if (left - 1 >= 0)
            left--;
        if (right + 1 < m.nCols)
            right++;
        int anotherRight = right;
        while (anotherRight >= left) {
            min = min2(min, m.values[i][anotherRight]);
            anotherRight--;
        }
    }
    return min;
}


int main() {
    matrix m1 = createMatrixFromArray((int[]) {10, 7, 5, 6,
                                               3, 11, 8, 9,
                                               4, 1, 12, 2}, 3, 4);

    printf("%d", getMinInArea(m1));
    return 0;
}
