//LeetCode -Stone Game - Medium
//https://leetcode.com/problems/stone-game/description/

// Calculate the odd and even sum at all points. Alice picks the one with max value among odd and even sum while bob picks the max of the end points
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int even = 0;
        int odd = 0;
        int n = piles.size();
        int i = 0;
        int j = n-1;
        int alice =0;
        int bob = 0;
        for(int i =0;i<n;i = i+2)
        {
            even += piles[i];
        }
        for(int i=1;i<n;i=i+2)
        {
            odd += piles[i];
        }
        while(i<=j)
        {
            if(even>odd)
            {
                if(i%2 == 0)
                {
                    alice += piles[i];
                    even -= piles[i];
                    i++;
                }
                else
                {
                    alice += piles[j];
                    even -= piles[j];
                    j--;
                }
            }
            else
            {
                if(i%2 == 1)
                {
                    alice += piles[i];
                    odd -= piles[i];
                    i++;
                }
                else
                {
                    alice += piles[j];
                    odd -= piles[j];
                    j--;
                }                
            }
            if(piles[i]>=piles[j])
            {
                bob += piles[i];
                if(i%2 == 0)
                {
                    even -= piles[i];
                }
                else
                {
                    odd -= piles[i];
                }
                i++;
            }
            else
            {
                bob += piles[j];
                if(j%2 == 0)
                {
                    even -= piles[j];
                }
                else
                {
                    odd -= piles[j];
                }
                j--;
            }
        }
        if(alice>bob)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
