#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

char* sortString(char* str) {

    char* temp = (char*)malloc(strlen(str) + 1);

    strcpy(temp, str);

    qsort(temp, strlen(temp), sizeof(char), compare);

    return temp;
}

char*** groupAnagrams(char** strs, int strsSize,
                      int* returnSize,
                      int** returnColumnSizes) {

    char** sorted = (char**)malloc(strsSize * sizeof(char*));

    for(int i = 0; i < strsSize; i++) {
        sorted[i] = sortString(strs[i]);
    }

    char*** result = (char***)malloc(strsSize * sizeof(char**));

    *returnColumnSizes = (int*)malloc(strsSize * sizeof(int));

    int groups = 0;

    int visited[100] = {0};

    for(int i = 0; i < strsSize; i++) {

        if(visited[i])
            continue;

        result[groups] = (char**)malloc(strsSize * sizeof(char*));

        int count = 0;

        for(int j = i; j < strsSize; j++) {

            if(strcmp(sorted[i], sorted[j]) == 0) {

                result[groups][count++] = strs[j];

                visited[j] = 1;
            }
        }

        (*returnColumnSizes)[groups] = count;

        groups++;
    }

    *returnSize = groups;

    return result;
}