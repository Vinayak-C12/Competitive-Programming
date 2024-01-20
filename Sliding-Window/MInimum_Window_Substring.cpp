//Leetcode - Minimum Window Substring - Hard
//https://leetcode.com/problems/minimum-window-substring/description/

class Solution {
public:
    string minWindow(string s, string t) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_map<char,int> um;
        for(int i = 0;i<t.size();i++)
        {
            um[t[i]]++;
        }
        int minstart = 0;
        int minlen = INT_MAX;
        int i = 0;
        int j = 0;
        int counter = t.size();// To keep count of the required letters in the substring
        while(j<s.size())
        {
            if(um[s[j]]>0)
            {
                counter--;
            }
            um[s[j]]--;
            j++;
            while(counter == 0)
            {
                if(j-i<minlen)
                {
                    minstart = i;
                    minlen = j-i;
                }
                um[s[i]]++;
                if(um[s[i]]>0)
                {
                    counter++;
                }
                i++;
            }
        }
        if(minlen!=INT_MAX)
        {
            return s.substr(minstart,minlen);
        }
        return "";
        
    }
};
