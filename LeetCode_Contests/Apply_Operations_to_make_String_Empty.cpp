//LeetCode Contest - Biweekly Contest - 124 - 17 Feb 2024

// 3039. Apply Operations to make the string Empty - Medium

//https://leetcode.com/contest/biweekly-contest-124/problems/apply-operations-to-make-string-empty/

class Solution {
public:
    string lastNonEmptyString(string s) {
        int n = s.size();
        unordered_map<char,int> um;
        string res="";
        int maxi = 0;
        for(auto c:s)
        {
            um[c]++;
            maxi = max(maxi,um[c]);
        }
        for(int i=n-1;i>=0;i--)
        {
            if(um[s[i]] == maxi)
            {
                res = s[i] + res;
                um[s[i]] = -1;
            }
        }
        return res;
    }
};
