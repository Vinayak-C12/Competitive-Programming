//Leetcode - Get Equal Substrings Within Budget - Medium
//https://leetcode.com/problems/get-equal-substrings-within-budget/description/?envType=daily-question&envId=2024-05-28

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) { // Sliding Window
        int n = s.size();
        int l = 0;
        int r = 0;
        int m = 0;
        int cur = 0;
        while(r<n)
        {
            cur += abs(s[r]-t[r]);
            while(cur>maxCost)
            {
                cur -= abs(s[l]-t[l]);
                l++;
            }
            m = max(m,r-l+1);
            r++;
        }
        return m;
    }
};
