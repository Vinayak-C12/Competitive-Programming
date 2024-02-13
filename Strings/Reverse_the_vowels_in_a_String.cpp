//LeetCode - Reverse the vowels in a String - Easy
//https://leetcode.com/problems/reverse-vowels-of-a-string/description/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    string reverseVowels(string s) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_set<char> us={'a','e','i','o','u','A','E','I','O','U'};
        int i = 0;
        int j = s.size() - 1;
        while(i<j)
        {
            if(us.find(s[i]) == us.end())
            {
                i++;
            }
            if(us.find(s[j]) == us.end())
            {
                j--;
            }
            if(us.find(s[i]) != us.end() && us.find(s[j]) != us.end())
            {
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};
