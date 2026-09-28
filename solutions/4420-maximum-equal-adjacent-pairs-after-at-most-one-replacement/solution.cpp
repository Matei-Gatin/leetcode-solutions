using namespace std;

class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        /*
        nums = [1,2,3,2] => [2,2,3,2]
        x = 1, y = 2 
        */

        unordered_map<long long, int> pair_counts;
        int res = 0;
 
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                res++;
            } else {
                int a = min(nums[i], nums[i + 1]);
                int b = max(nums[i], nums[i + 1]);

                long long key = ((long long)a << 32) | (long long)b;

                pair_counts[key]++;
            }    
        }

        int max_extra = pair_counts.empty() ? 0 : ranges::max(pair_counts | views::values);
        
        return res + max_extra;
    }
};
