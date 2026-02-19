class Solution
{
    public List<List<String>> groupAnagrams(String[] strs) 
    {
        Map<String, List<String>> codeMap = new HashMap<>();
        List<List<String>> result = new ArrayList<>();

        for (String str : strs)
        {
            
            int[] count = new int[26];

            for (char c : str.toCharArray())
            {
                count[c - 'a']++;
            }

            String code = createCode(count);

            codeMap.computeIfAbsent(code, k -> new ArrayList<>())
                    .add(str);
        }

        result.addAll(codeMap.values());

        return result;
    }

    public String createCode(int[] count)
    {
        StringBuilder sb = new StringBuilder();

        for (int c : count)
        {
            sb.append(c);
            sb.append('#');
        }

        return sb.toString();
    }
}
