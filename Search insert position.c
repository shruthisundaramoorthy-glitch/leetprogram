int searchInsert(int* num, int numSize, int target) {
int i;
for(i=0;i<numSize;i++)
if(num[i]==target||num[i]>target)
{
    return i;
    break;
}
return numSize;
}
