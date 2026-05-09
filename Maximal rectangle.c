#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int largestRectangleArea(int* heights, int n) {

    int* stack = (int*)malloc((n + 1) * sizeof(int));

    int top = -1;
    int maxArea = 0;

    for(int i = 0; i <= n; i++) {

        int currHeight;

        if(i == n)
            currHeight = 0;
        else
            currHeight = heights[i];

        while(top != -1 &&
              currHeight < heights[stack[top]]) {

            int h = heights[stack[top--]];

            int width;

            if(top == -1)
                width = i;
            else
                width = i - stack[top] - 1;

            maxArea = max(maxArea, h * width);
        }

        stack[++top] = i;
    }

    free(stack);

    return maxArea;
}

int maximalRectangle(char** matrix,
                     int matrixSize,
                     int* matrixColSize) {

    if(matrixSize == 0)
        return 0;

    int cols = matrixColSize[0];

    int* heights = (int*)calloc(cols, sizeof(int));

    int ans = 0;

    for(int i = 0; i < matrixSize; i++) {

        for(int j = 0; j < cols; j++) {

            if(matrix[i][j] == '1')
                heights[j]++;
            else
                heights[j] = 0;
        }

        ans = max(ans,
                  largestRectangleArea(heights, cols));
    }

    free(heights);

    return ans;
}