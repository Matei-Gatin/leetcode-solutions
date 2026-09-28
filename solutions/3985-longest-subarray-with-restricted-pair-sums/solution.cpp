using namespace std;

class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        /*
            nums = [2,3,5,3,2,1]
        */
        
        unordered_map<int, int> seen; 
        int res = 0;
        int l = 0;

        for (int r = 0; r < nums.size(); r++) { 
            if (r > 0) {
                int i = r - 1;

                while (i >= l) {
                    int req1 = nums[r] - nums[i];
                    int req2 = nums[r] + nums[i];

                    if (seen.count(req1) && seen[req1] >= l && seen[req1] != i) {
                        int left_most = min(i, seen[req1]);
                        l = left_most + 1;
                    }
                
                    if (seen.count(req2) && seen[req2] >= l && seen[req2] != i) {
                        int left_most = min(i, seen[req2]);
                        l = left_most + 1;
                    }

                    i--;
                }
            }

            // add the nr to the map
            seen[nums[r]] = r;

            // update res
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};
