class Solution 
{
    public void rotate(int[][] matrix) 
    {
         int iStart = 0;
         int jStart = 1;
         for (int i = iStart; i < matrix.length; i++)
         {
            for (int j = jStart; j < matrix.length; j++)
            {
                int temp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = temp;

                if (j == (matrix.length - 1))
                {
                    iStart++;
                    jStart++;
                }
            }
         }

        int len2DArr;
        len2DArr = matrix.length;

        for (int i = 0; i < matrix.length; i++)
        {
            for (int j = 0; j < (matrix.length / 2); j++)
            {
                var temp = matrix[i][j];
                matrix[i][j] = matrix[i][len2DArr - 1 - j];
                matrix[i][len2DArr - 1 - j] = temp;
            }
        }
    }

}
