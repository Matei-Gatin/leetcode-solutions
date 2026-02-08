class Solution {
    public int trap(int[] height) 
    {
        if (height.length == 0) return 0;

        int l = 0, r = height.length - 1;

        int maxLeft = height[l], maxRight = height[r];

        int result = 0;

        while (l < r)
        {
            if (maxLeft < maxRight)
            {
                l++;
                maxLeft = Math.max(height[l], maxLeft);
                result += maxLeft - height[l];
            } else
            {
                r--;
                maxRight = Math.max(height[r], maxRight);
                result += maxRight - height[r];
            }
        }    

        return result;
    }
}
