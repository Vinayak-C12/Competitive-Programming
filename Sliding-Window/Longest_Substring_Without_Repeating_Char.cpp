//Leetcode - Longest Substring Without Repeating Characters - Medium
//https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n  = s.size();
        int i = 0;// i is used to keep track of the start of the string 
        int j = 0;// j is used as  an iterator
        int res = 0;
        unordered_set<int> us;
        while(j<n)
        {
            if(us.find(s[j])==us.end())// If the element is not in the set, increment j and update the size
            {
                us.insert(s[j]);
                res = max(res, j-i+1);
                j++;
            }
            else
            {
                us.erase(s[i]);// If a repeated element is found, the the start of the string is erased and the new substring is checked for the same j
                i++;
            }
        }
        return res;
        
    }
};
