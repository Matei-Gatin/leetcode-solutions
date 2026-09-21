class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            You just do a single loop starting from day 1, and compare today vs yesterday.
            If today's price is higher than yesterday's price, you pretend you bought yesterday and sold today,
            and immediately add that difference to your total_profit. If today is lower than yesterday, you do nothing and move on.
        */

        int max_profit = 0;

        int min_buy_price = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            int current_price = prices[i];

            if (current_price < min_buy_price) {
                min_buy_price = current_price;
            } else {
                max_profit += current_price - min_buy_price;
                min_buy_price = current_price;
            }
        }

        return max_profit;
    }
};
