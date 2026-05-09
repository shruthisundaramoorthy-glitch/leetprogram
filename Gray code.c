/**
 * Note: The returned array must be malloced.
 */

int* grayCode(int n, int* returnSize) {

    int size = 1 << n;

    *returnSize = size;

    int* result = (int*)malloc(size * sizeof(int));

    for(int i = 0; i < size; i++) {

        result[i] = i ^ (i >> 1);
    }

    return result;
}