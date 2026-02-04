class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) return 0;
        
        Set<Integer> unique = new HashSet<>();
        for (int num : nums) {
            unique.add(num);
        }
        
        int maxLength = 0;
        for (Integer num : unique) {
            // Only start counting if this is the beginning of a sequence
            if (!unique.contains(num - 1)) {
                int currentLength = 1;
                int currentNum = num;
                
                // Count consecutive numbers forward
                while (unique.contains(currentNum + 1)) {
                    currentLength++;
                    currentNum++;
                }
                
                maxLength = Math.max(maxLength, currentLength);
            }
        }
        
        return maxLength;
    }
}
