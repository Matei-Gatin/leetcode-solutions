class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;

        int[] string1 = new int[26];
        
        for (char c : s.toCharArray()) {
            string1[c - 'a']++;
        }

        for (char c : t.toCharArray()) {
            string1[c - 'a']--;

            if (string1[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
}
