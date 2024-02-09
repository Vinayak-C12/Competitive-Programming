//LeetCode - Merge Strings Alternatively -  Easy
//https://leetcode.com/problems/merge-strings-alternately/description/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        string ans = "";
        int l = 0;
        int r = 0;
        int m = word1.size();
        int n = word2.size();
        while(l<m && r<n)
        {
            ans += word1[l];
            ans += word2[r];
            l++;
            r++;
        }
        while(l<m)
        {
            ans += word1[l];
            l++;
        }
        while(r<n)
        {
            ans += word2[r];
            r++;
        }
        return ans;
    }
};
