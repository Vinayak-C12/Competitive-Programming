//Leetcode - Grumpy Bookstore Owner - Medium - Sliding Window
//https://leetcode.com/problems/grumpy-bookstore-owner/description/?envType=daily-question&envId=2024-06-21

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = grumpy.size();
        int res = 0;
        for(int i=0;i<n;i++)
        {
            if(grumpy[i] == 0) // 1 indicates the owner is grumpy and the customers are not satisfied and vice versa. If grumpy[i] = 0 then the customers will be satified anyway so try to maximise the window where they not satisfied and add that max value to res to get the ans
            {
                res += customers[i];
            }
        }
        int ans = 0;
        for(int i=0;i<minutes;i++) // Try to maximise the window minutes where the customers can be satisfied
        {
            if(grumpy[i] == 1)
            {
                ans += customers[i];
            }
        }
        int mxans = ans;
        for(int r=minutes;r<n;r++) // Add or sub only when the owner is grumpy or else extra will be added in the answer
        {
            if(grumpy[r] == 1)
            {
                ans += customers[r];
            }
            if(grumpy[r-minutes] == 1)
            {
                ans -= customers[r-minutes];
            }
            mxans = max(mxans,ans);
        }
        return mxans+res;
    }
};

