class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        
        int max_l = height[l];
        int max_r = height[r];

        int res = 0;

        while (l < r) {
            if (max_l < max_r) {
                l++;
                max_l = max(max_l, height[l]);
                res += max_l - height[l];
            } else {
                r--;
                max_r = max(max_r, height[r]);
                res += max_r - height[r]; 
            }
        }

        return res;
    }
};
