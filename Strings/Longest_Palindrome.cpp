//Leetcode - Longest Palindrome - Easy
//https://leetcode.com/problems/longest-palindrome/description/?envType=daily-question&envId=2024-06-04

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> cset;
        int len=0;
        for(auto c:s)
        {
            if(cset.find(c) != cset.end())
            {
                cset.erase(c);
                len +=2;
            }
            else
            {
                cset.insert(c);
            }
        }
        if(!cset.empty())
        {
            len += 1;
        }
        return len;
    }
};
