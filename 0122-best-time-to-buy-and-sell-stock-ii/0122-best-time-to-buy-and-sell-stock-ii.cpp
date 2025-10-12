class Solution {
public:
    void buySell(vector<int> &prices, int i, int &profit) {
        // base condition
        if (i == prices.size() - 1) return;

        // if tomorrow's price is higher, we can earn profit
        if (prices[i + 1] > prices[i]) {
            profit += prices[i + 1] - prices[i];
        }

        // move to next day
        buySell(prices, i + 1, profit);
    }

    int maxProfit(vector<int>& prices) {
        int profit = 0;
        buySell(prices, 0, profit);
        return profit;
    }
};