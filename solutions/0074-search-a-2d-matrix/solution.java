class Solution {
    public boolean searchMatrix(int[][] matrix, int target) 
    {
        // O (log n * m)

        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) return false;

        int ROWS = matrix.length;
        int COLS = matrix[0].length;

        int top = 0;
        int bot = ROWS - 1;

        while (top <= bot)
        {
            int midRow = (top + bot) / 2;

            if (target < matrix[midRow][0])
            {
                bot = midRow - 1;
            } else if (target > matrix[midRow][COLS - 1])
            {
                top = midRow + 1;
            } else 
            {
                break;
            }
        }

        if (top > bot) return false;
        
        int idx = (top + bot) / 2;
        var qArray = matrix[idx];

        int l = 0;
        int r = qArray.length - 1;

        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (target == qArray[mid])
            {
                return true;
            }

            if (target > qArray[mid])
            {
                l = mid + 1;
            } else
            {
                r = mid - 1;
            }
        }

        return false;
    }
}
