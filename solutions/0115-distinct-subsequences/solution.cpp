class Solution {
public:
    int numDistinct(string s, string t) {
        // s = old
        // t = new

        std::size_t oldLen = s.size();
        std::size_t newLen = t.size();

        vector<std::uint64_t> ways(newLen + 1, 0); // first index is "" empty
        ways[0] = 1;

        for (int i = 0; i < oldLen; i++) {
            for (int j = newLen; j >= 1; j--) {
                if (s[i] == t[j - 1]) {
                    ways[j] += ways[j - 1];
                }
            }
        }

        return static_cast<int>(ways[newLen]);
    }
};
