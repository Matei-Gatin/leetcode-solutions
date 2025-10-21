class Solution {
    public String intToRoman(int num)
     {
        Map<Integer, String> symbols = Map.ofEntries(
                Map.entry(1000, "M"),
                Map.entry(900, "CM"),
                Map.entry(500, "D"),
                Map.entry(400, "CD"),
                Map.entry(100, "C"),
                Map.entry(90, "XC"),
                Map.entry(50, "L"),
                Map.entry(40, "XL"),
                Map.entry(10, "X"),
                Map.entry(9, "IX"),
                Map.entry(5, "V"),
                Map.entry(4, "IV"),
                Map.entry(1, "I")
        );

        List<Integer> values = new ArrayList<>(symbols.keySet());
        Collections.sort(values, Collections.reverseOrder());

        StringBuilder sb = new StringBuilder();

        for (int value : values)
        {
            while (num >= value)
            {
                num -= value;
                sb.append(symbols.get(value));
            }
        }

        return sb.toString();
        
    }
}
