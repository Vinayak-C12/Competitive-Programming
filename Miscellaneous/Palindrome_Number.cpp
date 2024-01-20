//Leetcode - Palindrome Number - Easy
//https://leetcode.com/problems/palindrome-number/description/

class Solution {
public:
    bool isPalindrome(int x) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(x<0)
        {
            return false;
        }
        long long sum = 0;
        int rem = 0;
        int t = x;
        while(t>0)
        {
            rem = t%10;
            sum = sum*10 + rem;
            t = t/10;
        }
        if(sum == x)
        {
            return true;
        }
        else
        {
            return false;
        }

        
    }
};
