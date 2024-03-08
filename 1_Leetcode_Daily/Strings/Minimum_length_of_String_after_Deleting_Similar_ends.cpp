//LeetCode - Minimum length of String after deleting Similar Ends - Medium
//https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/?envType=daily-question&envId=2024-03-05

class Solution {
public:
    int minimumLength(string s) {
        ios_base::sync_with_stdio(0);
        int n = s.size();
        int l = 0;
        int r = n-1;
        while(l<r) // This is not l<=r bcoz when at some point if l == r and is the characters match then l and r cross each other 
        {
            if(s[l] == s[r])
            {
                char c = s[l];
                while(l<=r && s[l] == c)
                {
                    l++;
                }
                while(r>=l && s[r] == c)
                {
                    r--;
                }
            }
            else
            {
                break;
            }
        }
        return r-l+1;
    }
};
