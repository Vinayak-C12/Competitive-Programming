//LeetCode - Factorial Trailing Zeroes - Medium
//https://leetcode.com/problems/factorial-trailing-zeroes/description/

class Solution {
public:
    int trailingZeroes(int n) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int ans = 0;
        while(n>=5)
        {
            int q = n/5; // The number of zeroes is the total number of factor of 5 which contribute ot the zero
            n = n/5;
            ans += q;
        }
        return ans;
    }
};
