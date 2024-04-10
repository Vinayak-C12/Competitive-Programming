//Leetcode - Valid Parenthesis String - Medium
//https://leetcode.com/problems/valid-parenthesis-string/description/?envType=daily-question&envId=2024-04-07

class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0, leftMax = 0;

        for (char c : s) {
            if (c == '(') {
                leftMin++;
                leftMax++;
            } else if (c == ')') {
                leftMin--;
                leftMax--;
            } else { //Consider both cases of opening and closing brace
                leftMin--;
                leftMax++;
            }
            if (leftMax < 0) return false; // Too many closing parenthesis present
            if (leftMin < 0) leftMin = 0; // Taking * as an empty string
        }
        
        return leftMin == 0;
    }
};
