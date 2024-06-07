//Leetcode - Append Characters to String to Make Subsequence - Medium
//https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/?envType=daily-question&envId=2024-06-03

class Solution {
public:
    int appendCharacters(string s, string t) {
        int m = s.size();
        int n = t.size();
        int j=0; // Pointer to string t
        for(int i=0;i<m;i++)
        {
            if(s[i] == t[j])
            {
                j++;
            }
            if(j==n) // To maintain the bound on string t and to indicate the string is already present in s
            {
                return 0;
            }
        }
        return n-j;
    }
};
