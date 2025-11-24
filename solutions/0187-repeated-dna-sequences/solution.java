class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        int lenStr = s.length();
        Map<String, Integer> freqMap = new HashMap<>();

        if (lenStr < 0)
        {
            return List.of();
        }

        if (lenStr == 10)
        {
            return List.of();
        }

        String currentSubstring;
        int lastIndex = 10;

        for (int i = 0; i <= (lenStr - 10); i++)
        {
            currentSubstring = s.substring(i, lastIndex);
            lastIndex++;

            freqMap.compute(currentSubstring, (k, v) -> v == null ? 1 : v + 1);
        }

        return freqMap.entrySet().stream()
            .filter(entry -> entry.getValue() >= 2)
            .map(Map.Entry::getKey)
            .toList();
    }
}
