//Leetcode - Make the string great - Easy
//https://leetcode.com/problems/make-the-string-great/description/?envType=daily-question&envId=2024-04-05

class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        stack<char> stk;
        for(int i =0;i<n;i++)
        {
            if(stk.empty())
            {
                stk.push(s[i]);
            }
            else if(tolower(stk.top()) == tolower(s[i]) && stk.top() != s[i])
            {
                stk.pop();
            }
            else
            {
                stk.push(s[i]);
            }
        }
        string ans = "";
        while(!stk.empty())
        {
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};
