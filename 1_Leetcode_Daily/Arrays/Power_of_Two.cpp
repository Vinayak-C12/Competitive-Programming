//LeetCode - Power of 2 - Easy
//https://leetcode.com/problems/power-of-two/description/?envType=daily-question&envId=2024-02-19

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0)
        {
            return false;
        }
        while(n % 2 == 0)
        {
            n = n/2;
        }
        return n == 1;
    }
};
