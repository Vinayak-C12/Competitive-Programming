//Leetcode - Evaluate Reverse Polish Notation
//https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
         
        stack<int> stk;
        
        for (int i = 0; i < tokens.size(); i++) {
            string token = tokens[i];
            //Here isdigit(token) will not work as the arg for isdigit() is supposed to be a char while token is a string. To get the char use isdigit(token[0])      as token[0] is a char and not a string
            if (token.size() > 1 || isdigit(token[0])) {
                stk.push(stoi(token));
                continue;
            }
            
            int num2 = stk.top();
            stk.pop();
            int num1 = stk.top();
            stk.pop();
            
            int result = 0;
            if (token == "+") {
                result = num1 + num2;
            } else if (token == "-") {
                result = num1 - num2;
            } else if (token == "*") {
                result = num1 * num2;
            } else {
                result = num1 / num2;
            }
            stk.push(result);
        }
        
        return stk.top();
        
        
    }
    
    
};
