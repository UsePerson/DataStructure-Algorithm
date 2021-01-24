#ifndef _SWAP_H_
#define _SWAP_H_
void swap(int *firstNum, int *secondNum){

    int tmp = *firstNum;
    *firstNum = *secondNum;
    *secondNum = tmp;
}
#endif