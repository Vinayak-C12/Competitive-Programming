//LeetCode - Find the Highest Altitude - Easy
//https://leetcode.com/problems/find-the-highest-altitude/description/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int res = 0;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans += gain[i];
            res = max(ans, res);
        }
        return res;
    }
};
