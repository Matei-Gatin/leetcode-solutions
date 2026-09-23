using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> seen(256, -1);

        int l = 0;
        int res = 0;

        for (int r = 0; r < s.size(); r++) {
            int current_char = s[r];

            if (seen[current_char] >= l) {
                l = seen[current_char] + 1;
            }

            seen[current_char] = r;

            res = max(res, r - l + 1);
        }

        return res;
    }
};
