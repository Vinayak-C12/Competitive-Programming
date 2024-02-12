//LeetCode - Palindromic Substrings - Medium
//https://leetcode.com/problems/palindromic-substrings/description/?envType=daily-question&envId=2024-02-10

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0;i<s.size();i++)
        {
            int even = palindromecount(s,i,i+1);// No of even length palindromes
            int odd = palindromecount(s,i,i);// No of odd length palindromes
            count += even + odd;
        }
        return count;
    }
private:
    int palindromecount(const string& s,int l,int r)
    {
        int count = 0;
        while(l>=0 && r<s.size() && s[l] == s[r])
        {
            count++;
            l--;
            r++;
        }
        return count;
    }
};
