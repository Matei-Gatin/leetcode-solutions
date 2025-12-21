class Solution {
    public int maxSubArray(int[] nums) {
        int currentSum = 0;
        int maxSum = nums[0];

        for (var num : nums)
        {
            currentSum = Math.max(num, currentSum + num);
            maxSum = Math.max(currentSum, maxSum);
    
            if (currentSum < 0)
            {
                currentSum = 0;
            }
        }

        return maxSum;
    }
}
