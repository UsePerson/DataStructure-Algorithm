#ifndef _MATCH_H_
#define _MATCH_H_
#include<string.h>


int match(char *s, char *pattern, int *failure){

    int i,j = 0;
    int sLen = strlen(s);
    int pLen = strlen(pattern);
    while( (i < sLen) && (j < pLen) ){

        if(s[i] == pattern[j]){
            i++;
            j++;
        }
        else if(j == 0){
            i++;
        }
        else{
            j = failure[j - 1] + 1;
        }
            
    }
    return ( (j == pLen) ? (i - pLen) : -1 );
}

#endif