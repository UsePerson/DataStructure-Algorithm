void swap(int *firstNum, int *secondNum){

    int tmp = *firstNum;
    *firstNum = *secondNum;
    *secondNum = tmp;
}