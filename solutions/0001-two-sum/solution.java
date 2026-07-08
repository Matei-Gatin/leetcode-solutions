class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> countMap = new HashMap<>(nums.length);

        int i, n = nums.length;
        for (i = 0; i < n; i++) { // O(n)
            int sub = target - nums[i]; // O(1)

            if (countMap.containsKey(sub)) { // O(1) time
                int index1 = countMap.get(sub); // (1) time
                return new int[]{index1, i};
            }

            countMap.put(nums[i], i); // (1) time
        }

        return new int[]{};
    }
}
