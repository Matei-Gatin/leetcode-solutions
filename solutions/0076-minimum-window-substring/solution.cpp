class Solution {
public:
    string minWindow(string s, string t) {
        /*
            s = "ADOBEC ODEBANC", t = "ABC"
        
            - put t string in a t_count
            - make a window_count
            - check if window_count[current_char] <= t_count[current_char] ==> it is a valid window 
        */
        
        vector<int> t_count(128, 0);

        for (int i = 0; i < t.size(); i++) {
            t_count[t[i]]++;
        }

        vector<int> window_count(128, 0);
        int min_size = INT_MAX;
        int perf_start = 0;
        int have = 0;
        int need = t.size();    
        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            int current_char = s[r];

            window_count[current_char]++;

            if (window_count[current_char] <= t_count[current_char]) {
                have++;
            }

            while (have == need) {
                int current_size = r - l + 1;

                if (current_size < min_size) {
                    min_size = current_size;
                    perf_start = l;
                }

                int left_char = s[l];
                window_count[left_char]--;

                if (window_count[left_char] < t_count[left_char]) {
                    have--;
                }
                
                l++;
            }
        }

        if (min_size == INT_MAX) {
            return "";
        }

        return s.substr(perf_start, min_size);
    }
};
