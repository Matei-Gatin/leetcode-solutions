using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        /*
            valid window = (current_window_length - most_frequent_char_count) <= k
            
            3 - 2 <= 2

            "A A B A B B A"
        */

        vector<int> count(26, 0);
        int res = 0;
        int l = 0;
        int max_f = 0;

        for (int r = 0; r < s.size(); r++) {
            count[s[r] - 'A']++;

            max_f = max(max_f, count[s[r] - 'A']);

            while ((r - l + 1) - max_f > k) {
                count[s[l] - 'A']--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};
