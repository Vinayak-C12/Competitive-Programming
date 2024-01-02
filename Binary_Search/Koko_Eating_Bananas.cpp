//Leetcode - Koko eating Bananas - Medium
//https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int res = r;
        while(l<=r)
        {
            int mid =(l+r)/2;
            long int hour = 0;
            for(int i=0;i<piles.size();i++)
            {
                hour+=ceil((double)piles[i]/mid);
            }
            if(hour<=h)
            {
                res = min(res,mid);
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return res;
        
    }
};
