class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Memoize Recursion
        std::vector<int> mem(cost.size() + 1, -1);
        return min(min_cost(mem, cost, 0), min_cost(mem, cost, 1));
    }

private:
    int min_cost(std::vector<int>& mem, std::vector<int>& cost, int i) {
        if (i >= cost.size()) return 0;

        if (mem[i] != -1) {
            return mem[i];
        }

        mem[i] = cost[i] + min(min_cost(mem, cost, i + 1), min_cost(mem, cost, i + 2));
        return mem[i];
    }
};
