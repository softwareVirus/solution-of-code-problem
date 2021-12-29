

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int **valid = (int **) malloc((matrixSize)*sizeof(int *));
    for(int i = 0; i < matrixSize; i++) {
        valid[i] = (int *) malloc(sizeof(int)*(*matrixColSize));
        for(int j = 0; j < *matrixColSize; j++) {
            valid[i][j] = matrix[i][j] == 0;
        }
    }
    for(int i = 0; i < matrixSize; i++) {
        for(int j = 0; j < *matrixColSize; j++) {
            if(valid[i][j] == 1) {
                int k = i,l = j;
                while(k >= 0) {
                    matrix[k][j] = 0;
                    k--;
                }
                while(l >= 0) {
                    matrix[i][l] = 0;
                    l--;
                }
                k = i,l = j;
                while(k < matrixSize) {
                    matrix[k][j] = 0;
                    k++;
                }
                while(l < *matrixColSize) {
                    matrix[i][l] = 0;
                    l++;
                }
            }
        }
    }
}
