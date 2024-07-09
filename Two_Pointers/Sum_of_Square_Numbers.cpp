//Leetcode -  Sum of Square Numbers - Meedium
//https://leetcode.com/problems/sum-of-square-numbers/?envType=daily-question&envId=2024-06-17

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = static_cast<long long>(sqrt(c));
        while(left<=right)
        {
            if(left*left + right*right == c)
            {
                return true;
            }
            else if(left*left + right*right <c)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return false;
    }
};
