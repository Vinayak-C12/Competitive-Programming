//Leetcode - Daily Temperatures - Medium
//https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<pair<int,int>> stk;
        for(int i=0;i<n;i++)
        {
            int currday = i;
            int currtemp = temperatures[i];
            while(!stk.empty()&&currtemp>stk.top().second)
            {
                int prevday = stk.top().first;
                int prevtemp = stk.top().second;
                stk.pop();
                res[prevday]= currday - prevday;
            }
            stk.push({currday,currtemp});
        }
        return res;
        
    }
};


