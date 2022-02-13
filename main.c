#include <stdio.h>
#include <assert.h>
#include "libs/data_structures/matrix/matrix.h"

void test_swapRows_swapFirstAndSecondRows() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1,
                                              2, 2, 2,
                                              3, 3, 3}, 3, 3);
    swapRows(m, 0, 1);
    matrix swapedMatrix = createMatrixFromArray((int[]) {2, 2, 2,
                                                         1, 1, 1,
                                                         3, 3, 3}, 3, 3);
    assert(m.nRows == swapedMatrix.nRows);
    assert(m.nCols == swapedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == swapedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_swapColumns_swapFirstAndSecondColumns() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              1, 2, 3,
                                              1, 2, 3}, 3, 3);
    swapColumns(m, 0, 1);
    matrix swapedMatrix = createMatrixFromArray((int[]) {2, 1, 3,
                                                         2, 1, 3,
                                                         2, 1, 3}, 3, 3);
    assert(m.nRows == swapedMatrix.nRows);
    assert(m.nCols == swapedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == swapedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_insertionSortRowsMatrixByRowCriteria_Sort() {
    matrix m = createMatrixFromArray((int[]) {4, 5, 6,
                                              7, 8, 9,
                                              1, 2, 3}, 3, 3);
    insertionSortRowsMatrixByRowCriteria(m, maxElementInRow);
    matrix expectedMatrix = createMatrixFromArray((int[]) {1, 2, 3,
                                                           4, 5, 6,
                                                           7, 8, 9}, 3, 3);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }
}

void test_insertionSortColsMatrixByColCriteria() {
    matrix m = createMatrixFromArray((int[]) {1, 8, 4, 5,
                                              2, 9, 5, 6,
                                              3, 10, 6, 11}, 3, 4);
    insertionSortColsMatrixByColCriteria(m, maxElementInCol);

    matrix expectedMatrix = createMatrixFromArray((int[]) {1, 4, 8, 5,
                                                           2, 5, 9, 6,
                                                           3, 6, 10, 11}, 3, 4);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }

}

void test_twoMatricesEqual_Equal() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);
    assert(twoMatricesEqual(m1, m2));
}

void test_isEMatrix_EMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0,
                                              0, 1, 0,
                                              0, 0, 1}, 3, 3);
    assert(isEMatrix(m));
}

void test_isSymmetricMatrix_isSymmetric() {
        matrix m = createMatrixFromArray((int[]) {1, 6, 10,
                                              6, 1, 3,
                                              10, 3, 1}, 3, 3);
    assert(isSymmetricMatrix(m));
}

void test_transposeSquareMatrix_isTransposeTrue() {
    matrix m = createMatrixFromArray((int[]) {1, 8, 4,
                                              10, 9, 8,
                                              3, 11, 2}, 3, 3);
    transposeSquareMatrix(m);

    matrix expectedMatrix = createMatrixFromArray((int[]) {1, 10, 3,
                                                           8, 9, 11,
                                                           4, 8, 2}, 3, 3);
    assert(twoMatricesEqual(m, expectedMatrix));
}

void test_getMinValuePos() {
    matrix m = createMatrixFromArray((int[]) {1, 8, 8,
                                              8, 8, 8,
                                              8, 8, 8}, 3, 3);
    position expectedMinPos = (position){0, 0};
    position minPos = getMinValuePos(m);
    assert(minPos.rowIndex == expectedMinPos.rowIndex);
    assert(minPos.colIndex == expectedMinPos.colIndex);
}

void test_getMaxValuePos() {
    matrix m = createMatrixFromArray((int[]) {100, 8, 8,
                                              8, 8, 8,
                                              8, 8, 16}, 3, 3);
    position expectedMinPos = (position){0, 0};
    position minPos = getMaxValuePos(m);
    assert(minPos.rowIndex == expectedMinPos.rowIndex);
    assert(minPos.colIndex == expectedMinPos.colIndex);
}
int main() {
    test_swapRows_swapFirstAndSecondRows();
    test_swapColumns_swapFirstAndSecondColumns();
    test_insertionSortRowsMatrixByRowCriteria_Sort();
    test_insertionSortColsMatrixByColCriteria();
    test_twoMatricesEqual_Equal();
    test_isEMatrix_EMatrix();
    test_isSymmetricMatrix_isSymmetric();
    test_transposeSquareMatrix_isTransposeTrue();
    test_getMinValuePos();
    test_getMaxValuePos();
    return 0;
}
