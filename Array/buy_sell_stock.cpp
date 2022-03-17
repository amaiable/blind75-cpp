class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> sell_prices(prices.size(), -1);
        sell_prices[sell_prices.size()-1] = prices[prices.size()-1];
        for (int i = prices.size()-2; i > -1; i--) {
            sell_prices[i] = max(sell_prices[i+1], prices[i]);
        }
        int answ = 0;
        for (int i = 0; i < prices.size()-1; i++) {
            answ = max(answ, sell_prices[i+1] - prices[i]);
        }
        return answ;
    }
};