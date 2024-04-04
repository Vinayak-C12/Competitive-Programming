//LeetCode - Count Elements with Maximum Frequency - Easy
//https://leetcode.com/problems/count-elements-with-maximum-frequency/description/?envType=daily-question&envId=2024-03-08

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> um;
        int m = 0;
        int res = 0;
        for(int i=0;i<nums.size();i++)
        {
            um[nums[i]]++;
            m = max(m,um[nums[i]]);
        }
        for(auto it=um.begin();it!=um.end();it++)
        {
            if(it->second == m)
            {
                res += m;
            }
        }
        return res;
    }
};
