int binarySearch(int list[], int left, int right, int searchNum){

    while( left <= right ){

        int middle = (left + right) / 2 ;
        if( list[middle] < searchNum ){

            left = middle + 1;
        }
        else if( list[middle] > searchNum ){

            right = middle - 1;
        }
        else{

            return middle;
        }
    }
    return -1;
}