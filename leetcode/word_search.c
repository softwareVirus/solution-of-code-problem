int **empty(int x,int y) {
    int **array = (int **) malloc(sizeof(int *)*x);
    for(int i = 0; i < x; i++) {
        array[i] = (int *) malloc(sizeof(int)*y);
        for(int j = 0; j < y; j++) array[i][j] = 0;
    }
    return array;
}

int length(char *word) {
    int size = 0;
    while(word[size] != '\0') size++;
    return size;
}

void dft(char **board,int i,int j,int size,int sizey,char *word,int index,int **visited,bool *answer) {   
    if(board[i][j] == word[index] && visited[i][j] == 0 && *answer != true) {
        visited[i][j] = 1;
        index++;
        if(index == length(word) && *answer == false) {
            *answer = true;
        }
        if(i+1 < size) {
            dft(board,i+1,j,size,sizey,word,index,visited,answer);
        }
        if(i-1 >= 0) {
            dft(board,i-1,j,size,sizey,word,index,visited,answer);
        }
        if(j+1 < sizey) {
            dft(board,i,j+1,size,sizey,word,index,visited,answer);
        }
        if(j-1 >= 0) {
            dft(board,i,j-1,size,sizey,word,index,visited,answer);
        } 
        visited[i][j] = 0;
    }  
}

bool search(char **board,int x,int y,int boardSize,int colSize,char *word) {
    int **visited = empty(boardSize,colSize);
    bool answer = false;
    dft(board,x,y,boardSize,colSize,word,0,visited,&answer);
    return answer;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < *boardColSize; j++) {
            if(search(board,i,j,boardSize,*boardColSize,word) == true) return true;
        }
    }
    return false;
}
