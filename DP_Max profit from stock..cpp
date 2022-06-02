class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        vector<int> buy(prices.size());
        vector<int> sell(prices.size());
        
        buy[0] = prices[0];
        
        for(int i = 1;i<prices.size();i++)
            buy[i] = min(buy[i-1],prices[i]);
        sell[prices.size()-1] = prices[prices.size()-1];
        
        for(int i = prices.size()-2;i>=0;i--)
            sell[i] = max(sell[i+1],prices[i]);
        vector<int> ans(prices.size());
        
        ans[0] = sell[0] - buy[0];
        for(int i = 1;i<prices.size();i++)
            ans[i] = max(ans[i-1],(sell[i] - buy[i]));
        
        return ans[prices.size()-1];
    }
};
