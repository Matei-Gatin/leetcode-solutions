using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // a + b + c = 0;
        /*
            [-1,0,1,2,-1,-4]
            [-4,-1,-1,-1,0,0,2,3] O(NlogN)

            sort the array O(NlogN)
            use 3 pointers
        */

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }

            int l = i + 1, r = nums.size() - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum < 0) {
                    l++;
                } else if (sum > 0) {
                    r--;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});

                    l++;
                    r--;

                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
            }
        }

        return res;
    }
};
