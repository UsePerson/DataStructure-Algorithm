#include<stdio.h>
#include<math.h>
#define MAX_SIZE 1000
#define SWAP(x,y,tmp)((tmp)=(x),(x)=(y),(y)=(tmp))

void sort(int [], int);

int main(){

    int  n;
    int list[MAX_SIZE];
    printf("Enter the size of array: ");
    scanf("%d",&n);
    if((n < 1) || (n > MAX_SIZE)){

        puts("Improper size");
        exit(0);
    }
    for(int i = 0 ; i < n ; i ++){

        list[i] = rand() % 1000;
        printf("%d ",list[i]);
    }
    sort(list, n);
    printf("\nSorted array: \n");
    for(int i = 0 ; i < n ; i ++){

        printf("%d ",list[i]);
    }
    puts("");
    return 0;
}
void sort(int list[], int n){

    int min, temp;
    for(int i = 0 ; i < (n - 1) ; i ++){

        min = i;
        for(int j = i + 1 ; j < n ; j ++){
            if(list[ j ] < list[ min ]){
                min = j;
            }
        }
        SWAP(list[i], list[min], temp);
    }
}




