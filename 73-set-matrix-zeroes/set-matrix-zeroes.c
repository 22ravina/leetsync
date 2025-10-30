void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int rows[matrixSize];
    int cols[matrixColSize[0]];
    
    for (int i = 0; i < matrixSize; i++)
        rows[i] = 0;
    for (int j = 0; j < matrixColSize[0]; j++)
        cols[j] = 0;

    // Step 1: Mark rows and columns
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            if (matrix[i][j] == 0) {
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }

    // Step 2: Set zeroes
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            if (rows[i] == 1 || cols[j] == 1)
                matrix[i][j] = 0;
        }
    }
}

    
