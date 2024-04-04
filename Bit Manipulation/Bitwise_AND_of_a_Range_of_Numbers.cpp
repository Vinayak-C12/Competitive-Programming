//LeetCode - Bitwise AND of Numbers Range - Medium
//https://leetcode.com/problems/bitwise-and-of-numbers-range/description/?envType=daily-question&envId=2024-02-21

// The approach is to find the common prefix of left and right. This is because the other bits that hav changed will become 0 in Bitwise AND operation. So keep right shifting left and right and compare them and keep the count. Return left left-shifted by count as the answer

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;
        if(left == 0)
        {
            return 0;
        }
        while(left < right)
        {
            left >>=1;
            right >>=1;
            count++;
        }
        return left << count;
    }
};
