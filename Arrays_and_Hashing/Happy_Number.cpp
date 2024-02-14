//LeetCode - Happy Number - Easy
//https://leetcode.com/problems/happy-number/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool isHappy(int n) {
        int sum = square(n);
        while(sum/10 != 0) // This loop breaks when the intermediate value is single digit but works when the starting value is a single digit. So find all single digit values that lead to true ie 1 and 7
        {
            sum = square(sum);
        }
        if(sum == 1 || sum == 7)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
private:
    int square(int s)
    {
        int sum =0;
        while(s>0)
        {
            sum += (s%10)*(s%10);
            s = s/10;
        }
        return sum;
    }
};
