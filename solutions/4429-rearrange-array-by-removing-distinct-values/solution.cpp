using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        /*
            create a tree map of nr: freq
            3: 3
            1: 2
            2: 1

            1,1,2,3,3,3
            append the nr 
        */

        sort(nums.begin(), nums.end());

        vector<vector<int>> buckets(nums.size());
        int streak_counter = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                streak_counter++;
            } else {
                streak_counter = 0;
            }
            
            buckets[streak_counter].push_back(nums[i]);   
        }

        vector<int> flat = buckets | views::join | ranges::to<vector>();
    
        return flat;
    }  
};
