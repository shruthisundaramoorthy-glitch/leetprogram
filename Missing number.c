 int missingNumber(int* nums, int numsSize) {
    int totalSum = 0;
    int n = numsSize;
    for (int i = 0; i <= n; i++) {
        totalSum += i;
    }
     for (int i = 0; i < n; i++) {
        totalSum -= nums[i];
    }
    return totalSum;
}