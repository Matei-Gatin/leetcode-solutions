class Solution {
public:
    int climb_stairs_helper(int n, std::vector<int>& mem) {
        if (n <= 2) {
            return n;
        }

        if (mem[n] != -1) {
            return mem[n];
        }

        mem[n] = climb_stairs_helper(n - 1, mem) + climb_stairs_helper(n - 2, mem);
        return mem[n];
    }
    
    int climbStairs(int n) {
        std::vector<int> mem(n + 1, -1);
        return climb_stairs_helper(n, mem);
    }
};
