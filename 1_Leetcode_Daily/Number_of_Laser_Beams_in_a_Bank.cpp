//Leetcode - Number of laser beams in a bank - Medium
//https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int m = bank.size();
        int n = bank[0].size();
        vector<int> laser(m);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                laser[i]+=(bank[i][j]=='1')?1:0;
            }
        }
        int l =0,r = 1,ans = 0;
        while(r<m)
        {
            if(laser[r]!=0)
            {
                ans+= laser[l]*laser[r];
                l =r;
                r++;
            }
            else
            {
                r++;
            }
        }
        return ans;
        
    }
};
