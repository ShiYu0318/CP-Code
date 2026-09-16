class Solution {
    // 20260915
    // O(n)
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, buy = prices[0];
        for(int i=1; i < prices.size(); ++i)
        {
            if(prices[i] < buy) buy = prices[i];
            else if(prices[i] - buy > ans) ans = prices[i] - buy;
        }
        return ans;
    }
};