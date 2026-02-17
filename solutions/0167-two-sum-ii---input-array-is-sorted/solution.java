class Solution {
    public int[] twoSum(int[] numbers, int target) {
        // index1 < index2
        // index1 != index2 -> so if the target is 2 you need to have 1 at two different possitions
        //
        
        int l = 0;
        int r = numbers.length - 1;

        while (l < r)
        {
            int currentSum = numbers[l] + numbers[r];

            if (currentSum == target)
            {
                return new int[]{l + 1, r + 1};
            }

            if (currentSum > target)
            {
                r--;
            } else
            {
                l++;
            }
        }

        return new int[0];
    }
}
