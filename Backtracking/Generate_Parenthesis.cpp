//Leetcode - Generate Parenthesis - Medium
//https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n,0,0,"",result);
        return result;        
    }
private:
//Backtracking Approach
    void generate(int n,int open,int close,string str,vector<string>& result)
    {   //If the no of open and close braces are equal and are equal to n then the case ends
        if(open==n&&close==n)
        {
            result.push_back(str);
            return;
        }
        //Open brace can be inserted when open count is less than n
        if(open<n)
        {
            generate(n,open+1,close,str+'(',result);
        }
        //CLose brace can be inserted only when close count is less than open count
        if(close<open)
        {
            generate(n,open,close+1,str+')',result);
        }
    }
};
