//Leetcode -  Reverse Substrings Between Each Pair of Parentheses - Medium
//https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/?envType=daily-question&envId=2024-07-11

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> stk;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '(')
            {
                stk.push(i);
            }
            else if(s[i] == ')')
            {ing brace
                reverse(s.begin()+stk.top(),s.begin()+i);
                stk.pop();
            }
        }
        string res = "";
        for(int i=0;i<n;i++)
        {
            if(s[i] != '(' && s[i] != ')')
            {
                res += s[i];
            }
        }
        return res;
    }
};

/*
-> Basically we just need to reverse the substring between 2 pair of braces
-> Use the stack to store the indices of opening braces
-> When u encounter a closing brace it means u hav to reverse the string between the opening and closing brace
-> The start index will be s.begin() + stk.top() - stk has the index of opening brace to s.begin() + i coz i is the current index and the index of closing brace
-> So the string will be directly reversed inplace itself
-> Next just iterate through the string and append all the characters other than braces to get the answer
*/
