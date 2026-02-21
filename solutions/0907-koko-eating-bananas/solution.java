class Solution 
{
    public int minEatingSpeed(int[] piles, int h)
    {
        int maxSpeed = Arrays.stream(piles)
            .max()
            .getAsInt();

        int low = 1;
        int high = maxSpeed;

        int res = maxSpeed;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long totalHours = 0;

            for (int pile : piles)
            {
                totalHours += (long) Math.ceil((double) pile / mid);
            }

            if (totalHours <= h)
            {
                res = mid;
                high = mid - 1;
            } else 
            {
                low = mid + 1;
            }
        }

        return res;
    }
}
