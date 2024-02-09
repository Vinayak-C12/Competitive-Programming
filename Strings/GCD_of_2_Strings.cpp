//LeetCode - GCD of 2 Strings - Easy
//https://leetcode.com/problems/greatest-common-divisor-of-strings/description/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        return (str1+str2 == str2+str1)?str1.substr(0,gcd(str1.size(),str2.size())):"";
    }
};
