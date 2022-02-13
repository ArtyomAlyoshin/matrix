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

matrix *createArrayOfMatrixFromArray(const int *values,
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


void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int *criteriaArray = (int *) malloc(sizeof(int) * m.nCols);
    int *additionalArray = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nCols; ++i) {
        for (int j = 0; j < m.nRows; ++j)
            additionalArray[j] = m.values[j][i];
        criteriaArray[i] = criteria(additionalArray, m.nRows);
    }
    for (int i = 0; i < m.nCols; ++i) {
        for (int j = i; j > 0 && criteriaArray[j - 1] > criteriaArray[j]; j--) {
            swap_(&criteriaArray[j - 1], &criteriaArray[j], sizeof(int));
            swapColumns(m, j, j - 1);
        }
    }
    free(criteriaArray);
    free(additionalArray);
}
