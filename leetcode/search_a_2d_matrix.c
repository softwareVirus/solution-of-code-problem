

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int i = 0;
    while(i < matrixSize) {
        if(matrix[i][(*matrixColSize)-1] >= target) break;
        i++;
    }
    if(i == matrixSize) return false;
    for(int j = 0; j < *matrixColSize; j++) {
        if(matrix[i][j] == target) return true;
    }
    return false;
}
