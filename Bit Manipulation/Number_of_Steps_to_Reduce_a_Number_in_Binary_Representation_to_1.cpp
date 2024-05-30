Leetcode - Number of Steps to Reduce a Number in Binary Representation to One - Medium
//https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/?envType=daily-question&envId=2024-05-29

class Solution {
public:
    int numSteps(string s) {
        int res = 0,carry = 0;
        int n = s.size();
        for(int i=n-1;i>0;i--)
        {
            if(s[i]-'0' + carry == 1)// Number is odd so 2 ops needed(addition and division)
            {
                res += 2;
                carry = 1;
            }
            else // even only 1 op
            {
                res++;
            }
        }
        return res+carry;// Coz if carry is there 2 ops needed but since msb should remain 1 no op is needed and no need to traverse till msb and traverse only till 2nd msb
    }
};
