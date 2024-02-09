//LeetCode - Reverse the words in a String - Medium
//https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<string> stk;
        int start = 0;
        for(int i = 0;i<=n;i++)
        {
            if(i == n || s[i] == ' ')
            {
                string subs = s.substr(start, i - start);
                if(!subs.empty())
                {
                    stk.push(subs);
                }
                start = i+1;
            }
        }
        string ans = "";
        while(!stk.empty())
        {
            ans += stk.top();
            ans += " ";
            stk.pop();
        }
        if(!ans.empty() && ans.back() == ' ')
        {
            ans.pop_back();
        }
        return ans;
    }
};
