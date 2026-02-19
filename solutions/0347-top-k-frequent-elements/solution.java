class Solution {
    public int[] topKFrequent(int[] nums, int k) 
    {
        // O(n) time O(n) space

        Map<Integer, Integer> freqMap = new HashMap<>();

        for (int n : nums)
        {
            freqMap.merge(n, 1, Integer::sum);
        }

        List<Integer>[] buckets = new ArrayList[nums.length + 1];

        IntStream.range(0, buckets.length)
            .forEach(i -> {
                buckets[i] = new ArrayList<>();
            });

        freqMap.forEach((key, value) -> 
        {
            int freq = value;
            int nr = key;

            buckets[freq].add(nr);
        });

        int[] result = new int[k];
        int index = 0;

        for (int i = buckets.length - 1; i >= 0 && index < k; i--)
        {
            ListIterator<Integer> iter = buckets[i].listIterator();

            while (iter.hasNext())
            {
                result[index] = iter.next();
                ++index;
            }
        }

        return result;
    }
}
