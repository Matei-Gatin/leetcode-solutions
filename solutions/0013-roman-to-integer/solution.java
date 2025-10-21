class Solution {
    public int romanToInt(String s) {
        // Create a map for the values

        Map<Character, Integer> symbols = Map.of(
            'I', 1, 'V', 5, 'X', 10, 'L', 50, 'C', 100, 'D', 500, 'M', 1000
        );

        // largest to smallest from left to right -> XXVII
        // exception is for XXIV

        int lenString = s.length();
        int total = 0;
        int i = 0;

        while (i < lenString)
        {
            if (i + 1 < lenString && symbols.get(s.charAt(i)) < symbols.get(s.charAt(i + 1)))
            {
                total += symbols.get(s.charAt(i + 1)) - symbols.get(s.charAt(i));
                i += 2;
            } else
            {
                total += symbols.get(s.charAt(i));
                i++;
            }
        }

        return total;
    }
}
