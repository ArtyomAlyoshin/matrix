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

int main() {
    test_swapRows_swapFirstAndSecondRows();
    test_swapColumns_swapFirstAndSecondColumns();
    test_insertionSortRowsMatrixByRowCriteria_Sort();
    test_insertionSortColsMatrixByColCriteria();
    return 0;
}
