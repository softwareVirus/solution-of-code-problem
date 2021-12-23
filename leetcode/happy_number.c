
int digit(int number) {
    int sum = 0;
    while(number > 0) {
        sum += (number % 10)*(number % 10);
        number /= 10;
    }
    return sum;
}

bool control(int *answer,int size,int number) {
    for(int i = 0; i < size; i++) {
        if(answer[i] == number) return true;
    }
    return false;
}

bool isHappy(int n){
    int size = 0;
    int *answer;
    while(n > 1) {
        if(control(answer,size,digit(n))) break;
        if(size == 0) {
            answer = (int *) malloc(sizeof(int));
        } else {
            answer = (int *) realloc(answer,sizeof(int)*(size+1));
        }
        answer[size] = n;
        n = digit(n);
        size++;
    }
    return n == 1;
}
