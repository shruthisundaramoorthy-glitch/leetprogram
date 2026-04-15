void rotate(int** matrix, int matrixSize, int* matrixColSize) {
 
    int temp,n;
    for(int i=0;i<matrixSize;i++)
    {
        for(int j=i+1;j<matrixColSize[0];j++)
        {
            temp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=temp;
        }
    }
    for(int i=0;i<matrixSize;i++)
    {
        n=matrixColSize[0]-1;
        for(int j=0;j<matrixColSize[0];j++)
        {
            if(j<n)
            {
                temp=matrix[i][j];
                matrix[i][j]=matrix[i][n];
                matrix[i][n]=temp;
                n--;
            }
        }
    }
}
 
