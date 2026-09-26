using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        /*
            ABABC ; k = 2

            valid window => current_sub_len - most_freq_char <= k
        */

        vector<int> seen(26, 0);
        int l = 0;
        int res = 0;
        int max_f = 0;

        for (int r = 0; r < s.size(); r++) {
            seen[s[r] - 'A']++;

            max_f = max(max_f, seen[s[r] - 'A']);

            while ((r - l + 1) - max_f > k) { // while not a valid window
                seen[s[l] - 'A']--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};
