class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_buy_price = prices[0];
        int max_profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            int current_price = prices[i];

            if (min_buy_price > current_price) {
                min_buy_price = current_price;
            } else {
                int profit = current_price - min_buy_price;
                max_profit = max(max_profit, profit);
            }
        }

        return max_profit;
    }
};
