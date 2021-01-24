#ifndef _FAILFUNCTION_H_
#define _FAILFUNCTION_H_
#include<string.h>
void failFunction(char *pattern, int *failure){

    int patternLen = strlen(pattern);
    failure[0] = -1;
    for(int base = 1 ; base < patternLen ; base ++ ){

        int i = failure[base - 1];
        while( (i >= 0) && (pattern[base] != pattern[i+1])  ){

            i = failure[i];
        }
        if(pattern[base] == pattern[i+1]){

            failure[base] = i + 1;
        }
        else{
            
            failure[base] = -1;
        }
    }
}
#endif