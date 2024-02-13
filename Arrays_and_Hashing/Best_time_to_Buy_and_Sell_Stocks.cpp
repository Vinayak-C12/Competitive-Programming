//LeetCode - Best time to buy and sell Stocks II - Medium
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = prices.size();
        int res = 0;
        for(int i =1;i<n;i++)
        {
            if(prices[i]>prices[i-1])
            {
                res += prices[i] - prices[i-1];
            }
        }
        return res;
    }
};
