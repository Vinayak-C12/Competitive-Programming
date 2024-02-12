//LeetCode - Ransom Note - Easy
//https://leetcode.com/problems/ransom-note/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> um;
        for(auto c: magazine)
        {
            um[c]++;
        }
        for(auto c : ransomNote)
        {
            um[c]--;
        }
        for(auto it = um.begin();it!=um.end();it++)
        {
            if(it->second<0)
            {
                return false;
            }
        }
        return true;
    }
};
