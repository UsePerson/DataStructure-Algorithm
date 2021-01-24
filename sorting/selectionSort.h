#ifndef _SELECTIONSORT_H_
#define _SELECTIONSORT_H_
#include "swap.h"

void selectionSort(int list[], int arrSize){

    int min;
    for(int i = 0 ; i < (arrSize - 1) ; i ++){

        min = i;
        for(int j = i + 1 ; j < arrSize ; j ++){
            if(list[ j ] < list[ min ]){
                min = j;
            }
        }
        swap(&list[i], &list[min]);
    }
}
#endif



