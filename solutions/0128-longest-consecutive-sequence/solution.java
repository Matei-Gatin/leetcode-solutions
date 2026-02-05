class Solution {
    public int longestConsecutive(int[] nums)
    {
        Set<Integer> unique = new HashSet<>();
        Arrays.stream(nums).forEach(unique::add);

        int maxLength = 0;
        for (var n : unique)
        {
            if (!unique.contains(n - 1))
            {
                int currentLength = 1;
                int currentNum = n;

                while (unique.contains(currentNum + 1))
                {
                    currentLength++;
                    currentNum++;
                }

                maxLength = Math.max(maxLength, currentLength);
            }
        }

        return maxLength;
    }
}
