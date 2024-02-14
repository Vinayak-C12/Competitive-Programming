//LeetCode - Word Pattern - Easy
//https://leetcode.com/problems/word-pattern/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> um; // Map between char amd the corresponding string
        vector<string> str; // Separate the words and store them in the vector
        unordered_set<string> us; // To check if the values in the map are same
        int start =0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == ' ')
            {
                string temp = s.substr(start,i-start);
                str.push_back(temp);
                start = i+1;
            }
        }
        str.push_back(s.substr(start,s.size()-start));// Bcoz the last index is not space and the last word will not be appended into the vector
        if(str.size() != pattern.size()) // pattern len and the word len must be the same
        {
            return false;
        }
        for(int i=0;i<pattern.size();i++)
        {
            if(um.find(pattern[i]) != um.end())
            {
                if(um[pattern[i]] != str[i])
                {
                    return false;
                }
            }
            else
            {
                um[pattern[i]] = str[i];
            }
        }
        for(auto it:um)
        {
            if(us.find(it.second) != us.end())
            {
                return false;
            }
            else
            {
                us.insert(it.second);
            }
        }
        return true;
    }
};
