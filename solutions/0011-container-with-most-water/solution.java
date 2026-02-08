class Solution {
    public int maxArea(int[] height) 
    {
        int l = 0, r = height.length - 1;

        int maxArea = 0;

        while (l < r)
        {
            int currentArea = (r - l) * Math.min(height[r], height[l]);

            int minHeight = Math.min(height[r], height[l]);

            if (minHeight == height[l])
            {
                l++;
            } else
            {
                r--;
            }

            maxArea = Math.max(maxArea, currentArea);
        }

        return maxArea;    
    }
}
