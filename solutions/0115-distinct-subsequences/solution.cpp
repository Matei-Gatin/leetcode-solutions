class Solution {
public:
    int numDistinct(string s, string t) {
        // s = rabbbit (old)
        // t = rabbit (new)

        int oldLen = s.size();
        int newLen = t.size();

        std::vector<std::uint64_t> ways(newLen + 1, 0);
        ways[0] = 1;

        for (int i = 0; i < oldLen; i++) {
            for (int j = newLen; j >= 1; j--) {
                if (s[i] == t[j - 1]) {
                    ways[j] += ways[j - 1];
                }
            }
        }

        return ways[newLen];
    }
};
