//LeetCode - Isomorphic Strings - Easy
//https://leetcode.com/problems/isomorphic-strings/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> um;
        unordered_set<char> us;// To check if two keys hav the same value
        for(int i =0;i<s.size();i++)
        {
            um[s[i]] = t[i];
        }
        for(auto it:um)
        {
            if(us.find(it.second) != us.end())
            {
                return false;
            }else
            {
                us.insert(it.second);
            }
        }
        for(int i=0;i<s.size();i++)
        {
            s[i] = um[s[i]];
        }
        return s == t;
    }
};
