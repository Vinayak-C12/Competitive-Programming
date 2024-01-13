//Leetcode - Minimum number of steps to make 2 strings anagram - Medium
//https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> um;
        int m  = s.size();
        int n  = t.size();
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        for(int i = 0 ;i<n;i++)
        {
            um[t[i]]++;
            um[s[i]]--;
        }
        int sum = 0;
        for(auto it = um.begin();it!=um.end();it++)
        {
            if(it->second>0)
            {
                sum += it->second;
            }
        }
        return sum;
        
    }
};
