//LeetCode - Length of last Word - Easy
//https://leetcode.com/problems/length-of-last-word/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int j = n-1;
        int len = 0;
        while(j>=0)
        {
            if(s[j] == ' ')
            {
                j--;
            }
            else
            {
                while(j>=0 && s[j] != ' ')
                {
                    len++;
                    j--;
                }
                break;
            }
        }
        return len;
    }
};
