class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int mn = numeric_limits<int>::max();            
            int max_profit = 0;

            for (int i = 0; i < prices.size(); i++) {
                if (prices[i] < mn) {
                    mn = prices[i];
                } else if (prices[i] - mn > max_profit) {
                    max_profit = prices[i] - mn;
                }
            }

            return max_profit;
        }
};