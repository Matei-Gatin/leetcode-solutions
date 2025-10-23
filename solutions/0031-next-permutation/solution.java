class Solution {
    public void nextPermutation(int[] nums) {
        int len = nums.length;
        int idxPivot = -1;

        // Fint pivot (rightmost index where nums[i-1] < nums[i])
        for (int i = len - 1; i > 0; i--)
        {
            if (nums[i - 1] < nums[i])
            {
                idxPivot = i - 1;
                break;
            }
        }
        
        // No pivot found (entire array descending)
        if (idxPivot == -1)
        {
            reverse(nums, 0, len - 1); // reverse entire array;
            return;
        }

        // Find swap index (first number > pivot from right)
        int swapIndex = -1;
        for (int i = len - 1; i > idxPivot; i--)
        {
            if (nums[i] > nums[idxPivot])
            {
                swapIndex = i;
                break;
            }
        }

        // Swap pivot with swap index;
        swap(nums, idxPivot, swapIndex);

        // Reverse right part (start at idxPivot + 1)
        reverse(nums, idxPivot + 1, len - 1);
    }

    // Helper method:
    public void reverse(int[] nums, int left, int right)
    {
        while(left < right)
        {
            swap(nums, left++, right--);
        }
    }
    
    // Helper method:
    public void swap(int[] nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
