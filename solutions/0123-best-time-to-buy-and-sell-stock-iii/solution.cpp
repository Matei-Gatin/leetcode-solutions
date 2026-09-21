using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            prices = [3,3,5,0,0,3,1,4]
        */

        int buy1 = INT_MAX;
        int profit1 = 0;
        int buy2 = INT_MAX;
        int profit2 = 0;

        for (int current_price : prices) {
            buy1 = min(buy1, current_price);
            profit1 = max(profit1, current_price - buy1);

            buy2 = min(buy2, current_price - profit1);
            profit2 = max(profit2, current_price - buy2);
        }

        return profit2;
    }
};
