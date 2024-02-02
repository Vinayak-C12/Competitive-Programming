//LeetCode - Sign of the Product of the array - Easy
//https://leetcode.com/problems/sign-of-the-product-of-an-array/description/

class Solution {
public:
    int arraySign(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int count = 0;
        for(auto i : nums)
        {
            if(i < 0)
            {
                count++;
            }
            else if(i == 0)
            {
                return 0;
            }
        }
        if(count % 2 == 0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
};
