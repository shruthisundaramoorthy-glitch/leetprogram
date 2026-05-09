#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * addBinary(char * a, char * b){

    int len1 = strlen(a);
    int len2 = strlen(b);

    int maxLen;

    if(len1 > len2)
        maxLen = len1;
    else
        maxLen = len2;

    char* result = (char*)malloc(maxLen + 2);

    int i = len1 - 1;
    int j = len2 - 1;

    int k = maxLen;

    int carry = 0;

    result[maxLen + 1] = '\0';

    while(i >= 0 || j >= 0 || carry) {

        int sum = carry;

        if(i >= 0)
            sum += a[i--] - '0';

        if(j >= 0)
            sum += b[j--] - '0';

        result[k--] = (sum % 2) + '0';

        carry = sum / 2;
    }

    return result + k + 1;
}