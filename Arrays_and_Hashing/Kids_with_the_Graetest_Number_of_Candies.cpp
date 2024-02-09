//LeetCode - Kids with Greatest Number of Candies - Easy
//https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int m = *max_element(candies.begin(),candies.end());
        vector<bool> res(candies.size());
        for(int i = 0;i<candies.size();i++)
        {
            if(candies[i] + extraCandies >=m)
            {
                res[i] = true;
            }
            else
            {
                res[i] = false;
            }
        }
        return res;
    }
};
