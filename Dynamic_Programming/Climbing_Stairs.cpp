//Leetcode - Climbing Stairs - Easy
//https://leetcode.com/problems/climbing-stairs/description/?envType=daily-question&envId=2024-01-18

class Solution {
public:
    int climbStairs(int n) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(n==1)
        {
            return 1;
        }
        if(n==2)
        {
            return 2;
        }
        vector<int> res(n,0);
        res[0]=1;
        res[1]=2;
        for(int i=2;i<n;i++)
        {
            res[i] = res[i-1]+res[i-2];
        }
        return res[n-1];
    }
};
