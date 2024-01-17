//Leetcode - Best time to BUy and Sell Stocks - Easy
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = prices.size();
        int l = 0;
        int r = 1;
        int res = 0;
        while(r<n)
        {
            if(prices[l]<=prices[r])
            {
                res = max(res, prices[r]-prices[l]);
            }
            else
            {
                l = r;
            }
            r++;
        }
        
        return res;
        
    }
};
