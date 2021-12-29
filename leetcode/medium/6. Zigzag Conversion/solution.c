#include <stdlib.h>

char * convert(char * s, int numRows){
    int size = 0;
    while(s[size] != '\0') size++;
    if(numRows == 1) return s;
    int index_answer = 0;
    char *answer = (char *) malloc(sizeof(char)*(size+1));
    
    for(int i = 0; i < numRows; i++) {
        for(int j = i; j < size; j= j+(numRows*2-2)) {
            answer[index_answer] = s[j];
            index_answer++;
            if(index_answer >= size) break;
            if(i != 0 && i != numRows - 1) {
                if(j+(2*numRows-2-2*i) < size) {
                    int index = j+(2*numRows-2-2*i);
                    answer[index_answer] = s[index];
                    index_answer++;
                    if(index_answer >= size) break;
                }
            }
        }
    }
    answer[size] = '\0';
    return answer;
}
