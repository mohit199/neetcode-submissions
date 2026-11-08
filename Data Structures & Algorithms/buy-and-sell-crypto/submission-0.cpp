class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int preMin = prices[0];
        int profit = 0;

        for(int i = 1; i < prices.size(); i++)
        {
            profit = max(profit, prices[i]-preMin);
            preMin = min(preMin, prices[i]);
        }
        return profit;
    }
};
