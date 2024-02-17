//Leetcode - Maximum Number of Vowels in a Substring of Given Length - Medium
//https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/?envType=study-plan-v2&envId=leetcode-75

auto init_io = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();
class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        unordered_set<char> us = {'a','e','i','o','u'};
        int len = 0;
        int longest = 0;
        for(int i=0;i<k;i++)
        {
            if(us.find(s[i]) != us.end())
            {
                len++;
            }
        }
        longest = len;
        for(int i=k;i<n;i++)
        {
            if(us.find(s[i-k]) != us.end())
            {
                len--;
            }
            if(us.find(s[i]) != us.end())
            {
                len++;
            }
            longest = max(len,longest);
            if(longest == k)
            {
                return k;
            }
        }
        return longest;
    }
};
