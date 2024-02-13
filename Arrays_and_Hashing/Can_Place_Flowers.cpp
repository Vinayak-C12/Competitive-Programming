//LeetCode - Can place Flowers - Easy
//https://leetcode.com/problems/can-place-flowers/description/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        int count = 0;
        if(n == 0)
        {
            return true;
        }
        for(int i=0;i<m;i++)
        {
            if(flowerbed[i] == 0)
            {
            bool left = (i == 0) || flowerbed[i-1] == 0;
            bool right = (i == m-1) || flowerbed[i+1] == 0;

            if(left && right)
            {
                flowerbed[i] = 1;
                count++;
            }
            if(count>=n)
            {
                return true;
            }
            }
        }
        return count>=n;
    }
};
