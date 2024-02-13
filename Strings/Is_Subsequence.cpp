//LeetCode - Is Subsequence - Easy
//https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool isSubsequence(string s, string t) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = t.size();
        int p = 0;
        if(s == "")
        {
            return true;
        }
        for(int i =0;i<n;i++)
        {
            if(t[i] == s[p])
            {
                p++;
            }
            if(p == s.size())
            {
                return true;
            }
        }
        return false;;
    }
};
