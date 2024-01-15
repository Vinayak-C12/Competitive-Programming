//Leetcode - Largest Rectangle in a Histogram - Hard
//https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int res = 0;
        stack<pair<int,int>> stk;
        int n = heights.size();
        
        for(int i =0 ;i<n;i++)
        {
            int start = i;
            while(!stk.empty() && stk.top().second>heights[i])
            {
                int index = stk.top().first;
                int height = stk.top().second;
                int width = i-index;
                stk.pop();
                res = max(res, height*width);
                start = index;
            }
            stk.push({start,heights[i]});
        }
        
        while(!stk.empty())
        {
            int w = n - stk.top().first;
            res = max(res, w*stk.top().second);
            stk.pop();
        }
        return res;
        
    }
};
