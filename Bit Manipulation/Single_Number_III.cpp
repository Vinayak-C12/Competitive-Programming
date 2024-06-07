//Leetcode - Single Number III - Medium
//https://leetcode.com/problems/single-number-iii/description/?envType=daily-question&envId=2024-05-31

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n  = nums.size();
        int x = 0;
        int num1=0;
        int num2=0;
        for(int i=0;i<n;i++)
        {
            x^= nums[i];
        }
        int k=0;
        while(((x>>k)&1) != 1)
        {
            k++;
        }
        for(int i=0;i<n;i++)
        {
            if((nums[i]>>k)&1 == 1)
            {
                num1 ^= nums[i];
            }
            else
            {
                num2 ^= nums[i];
            }
        }
        return {num1,num2};
    }
};

/*
LOGIC:
->The xor of 2 same numbers is 0 and the xor of 0 and anything is the number itself.These 2 r the basis for the solution
->Now when we take the xor of the entire array we will be left with the xor of our required numbers
->Now from this we need to decode the 2 numbers
->If a bit in the result is 1 it means the bits are different which means one of the numbers has 0 and the other is 1. 0 means they hav the same bits
->Now on the basis if this we can divide all the numbers into 2 groups at every ith bit which 1 which r groups having 0 and the other 1
->Since duplicates r present the duplicates of group 0 must also hav 0 bit and same goes for group having the bit as 1
->SO taking the xor of these 2 groups separately will give us the 2 numbers as both the numbers belong to different group and the duplicates cancel each other
-> So identify  the first bit from the right which is 1 and get its index
->Next run a loop to check that bit of each number,divide them into groups and take their xor to get the 2 numbers
*/
