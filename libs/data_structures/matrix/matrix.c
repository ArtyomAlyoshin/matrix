#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix createMatrixFromArray(const int *a, size_t nRows,
                             size_t nCols) {
    matrix m = getMemMatrix(nRows, nCols);
    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];
    return m;
}

matrix *
createArrayOfMatrixFromArray(const int *values,
                             size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}

matrix *getMemArrayOfMatrices(int nMatrices,
                              int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; i++)
        free(m.values[i]);
    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix((matrix) ms[i]);
}

void inputMatrix(matrix m) {
    for (int row = 0; row < m.nRows; row++)
        for (int col = 0; col < m.nCols; col++)
            scanf("%d", &m.values[row][col]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix m) {
    for (int row = 0; row < m.nRows; row++)
        for (int col = 0; col < m.nCols; col++)
            printf("%d ", m.values[row][col]);
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        outputMatrix(ms[i]);
        printf("/n");
    }

}


void swapRows(matrix m, int i1, int i2) {
    swap_(&m.values[i1], &m.values[i2], sizeof(int *));
}

void swapColumns(matrix m, int j1, int j2) {
    for (int row = 0; row < m.nRows; row++)
        swap_(&m.values[row][j1], &m.values[row][j2], sizeof(int));
}


void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria)(int *, int)) {
    int *array = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nRows; ++i) {
        array[i] = criteria(m.values[i], m.nCols);
    }
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = i; j > 0 && array[j - 1] > array[j]; j--) {
            swap_(&array[j - 1], &array[j], sizeof(int));
            swapRows(m, j, j - 1);
        }
    }
    free(array);
}

//исправлена сортировка
void selectionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int *criteriaArray = (int *) malloc(sizeof(int) * m.nCols);
    int *additionalArray = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nCols; ++i) {
        for (int j = 0; j < m.nRows; ++j)
            additionalArray[j] = m.values[j][i];
        criteriaArray[i] = criteria(additionalArray, m.nRows);
    }

    for (int i = 0; i < m.nCols - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < m.nCols; j++)
            if (criteriaArray[j] < criteriaArray[minPos])
                minPos = j;
        swap(&criteriaArray[i], &criteriaArray[minPos]);
        swapColumns(m, i, minPos);
    }
    free(criteriaArray);
    free(additionalArray);
}

bool isSquareMatrix(matrix m) {
    return (bool) m.nRows == m.nCols;
}

//исправлен иф
bool twoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows == m2.nRows && m1.nCols == m2.nCols)
        return false;
    else {
        bool isEqual = false;
        for (size_t i = 0; i < m1.nRows; i++) {
            for (size_t j = 0; j < m1.nCols; j++) {
                isEqual = (bool) (m1.values[i][j] == m2.values[i][j]);
                if (isEqual == false)
                    return false;
            }
        }
        return isEqual;
    }
}

bool isEMatrix(matrix m) {
    bool isE = true;
    size_t i = 0;
    while (isE && i < m.nRows) {
        size_t j = 0;
        while (isE && j < m.nCols) {
            if (i == j)
                isE = (bool) (m.values[i][j] == 1);
            else
                isE = (bool) (m.values[i][j] == 0);
            j++;
        }
        i++;
    }
    return (bool) isE;
}

//справлен индекс
bool isSymmetricMatrix(matrix m) {
    bool isSymmetric = true;
    for (int i = 0; i < m.nRows; ++i)
        for (int j = i + 1; j < m.nCols; ++j) {
            isSymmetric = (bool) (m.values[i][j] == m.values[j][i]);
            if (isSymmetric == 0)
                return false;
        }
    return isSymmetric;
}

void transposeSquareMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = i + 1; j < m.nCols; ++j) {
            swap_(&m.values[i][j], &m.values[j][i], sizeof(int));
        }
    }
}

position getMinValuePos(matrix m) {
    position min = (position) {0, 0};
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            position positionNow = (position) {i, j};
            if ((m.values[positionNow.rowIndex][positionNow.colIndex]) < m.values[min.rowIndex][min.colIndex])
                min = positionNow;
        }
    }
    return min;
}

position getMaxValuePos(matrix m) {
    position max = (position) {0, 0};
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            position positionNow = (position) {i, j};
            if ((m.values[positionNow.rowIndex][positionNow.colIndex]) > m.values[max.rowIndex][max.colIndex])
                max = positionNow;
        }
    }
    return max;
}

matrix mulMatrices(matrix m1, matrix m2) {
    assert(m1.nCols == m2.nRows);
    matrix newMatrix = getMemMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m2.nCols; j++) {
            newMatrix.values[i][j] = 0;
            for (int k = 0; k < m1.nCols; k++) {
                newMatrix.values[i][j] += m1.values[i][k] * m2.values[k][j];
            }
        }
    }
    return (matrix) newMatrix;
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float rowsCriteria[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        rowsCriteria[i] = criteria(m.values[i], m.nCols);

    for (int i = 1; i < m.nRows; i++)
        for (int j = i; j > 0 && rowsCriteria[j - 1] > rowsCriteria[j]; j--) {
            swap_(&rowsCriteria[j - 1], &rowsCriteria[j], sizeof(float));
            swapRows(m, j, j - 1);
        }
}

