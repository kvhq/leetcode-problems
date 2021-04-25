//Number: 121
//Name: Best Time to Buy and Sell Stock
//Tags: array

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        int cur_low = prices[0];
        int max_profit = 0;
        for (size_t i = 1; i < prices.size(); ++i) {
            if (prices[i] > cur_low) {
                max_profit = max(max_profit, prices[i] - cur_low);
            } else cur_low = prices[i];
        }
        return max_profit;
    }
};

