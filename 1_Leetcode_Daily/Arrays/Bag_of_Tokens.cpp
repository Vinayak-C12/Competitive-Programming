//LeetCode - Bag of tokens - Medium 
//https://leetcode.com/problems/bag-of-tokens/submissions/1193525846/?envType=daily-question&envId=2024-03-04

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score = 0;
        int res = 0;
        int n = tokens.size();
        int l = 0;
        int r = n-1;
        while(l<=r)
        {
            if(power>=tokens[l]) // PLaying face-up
            {
                power -= tokens[l];
                l++;
                score++;
                res = max(res,score);
            }
            else if(score>0) // Playing Face-Down
            {
                power += tokens[r];
                r--;
                score--;
            }
            else // When we dont hav both tokens and power cant proceed any further
            {
                break;
            }
        }
        return res;
    }
};
