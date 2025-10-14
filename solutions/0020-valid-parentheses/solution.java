class Solution {
    public boolean isValid(String s) {
        if (s.isEmpty()) return true;

        Map<Character, Character> map =
                Map.of(')','(',']','[','}','{');
        Deque<Character> stack =
                 new ArrayDeque<>();
        
        for (char c : s.toCharArray())
        {
            if (map.containsKey(c))
            {
                char val = map.get(c);
                if (stack.isEmpty() || stack.pop() != val)
                {
                    return false;
                }
            } else
            {
                stack.push(c);
            }
        }

        return stack.isEmpty();
    }
}
