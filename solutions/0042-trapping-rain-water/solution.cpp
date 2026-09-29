class Solution {
public:
    int trap(vector<int>& height) {
        /*
            height = [0,1,0,2,1,0,1,3,2,1,2,1]

            [4,2,0,3,2,5]

            res = 0


        */

        int l = 0;
        int r = height.size() - 1;

        int res = 0;
        int max_hl = height[l];
        int max_hr = height[r];

        while (l < r) {
            if (height[l] < height[r]) {
                l++;
                
                max_hl = max(max_hl, height[l]);
                
                res += max_hl - height[l];
            } else {
                r--;

                max_hr = max(max_hr, height[r]);

                res += max_hr - height[r];
            }
        } 

        return res;
    }
};
