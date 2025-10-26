class Solution {
    public int removeElement(int[] nums, int val) {
        // [2,3,3,2,5,2,3] val=3
        // 

        int occurences = 0;
        int numsLength = nums.length;
        int finalLength = 0;

        for (int i = 0; i < numsLength; i++)
        {
            if (nums[i] == val)
            {
                ++occurences;
            } else
            {
                nums[i - occurences] = nums[i];
                finalLength++;
            }
        }

        return finalLength;
    }
}
