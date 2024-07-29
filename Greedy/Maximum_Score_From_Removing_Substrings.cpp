//Leetcode - Maximum Score From Removing Substrings - Medium
//https://leetcode.com/problems/maximum-score-from-removing-substrings/description/?envType=daily-question&envId=2024-07-12

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int max_score,min_score;
        string top,bot;
        int res = 0;
        if(x>y)
        {
            top = "ab";
            max_score = x;
            bot = "ba";
            min_score = y;
        }
        else
        {
            top = "ba";
            max_score = y;
            bot = "ab";
            min_score = x;        
        }
        vector<char> stk;
        for(char c:s)
        {
            if(c == top[1] && !stk.empty() && stk.back() == top[0])
            {
                res += max_score;
                stk.pop_back();
            }
            else
            {
                stk.push_back(c);
            }
        }
        vector<char> stk2;
        for(char c:stk)
        {
            if(c == bot[1] && !stk2.empty() && stk2.back() == bot[0])
            {
                res += min_score;
                stk2.pop_back();
            }
            else
            {
                stk2.push_back(c);
            }
        }
        return res;
    }
};

/*
Logic:
-> First we see which give more value
-> Then we first remove the substrings that give more value using a stack
-> Next we remove the ones that give less value from the stack and then return the result
-> Note that once remove all "ab" from the string we will never get "ab" again from the removal of "ba" and vice versa. So this logic works
*/
