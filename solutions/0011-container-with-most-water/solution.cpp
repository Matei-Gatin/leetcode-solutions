using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;

        int res = 0;

        while (l < r) {
            int current_area = (r - l) * min(height[l], height[r]);

            res = max(res, current_area);

            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }

        return res;
    }
};
