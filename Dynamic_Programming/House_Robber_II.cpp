//Leetcode - House Robber II - Medium
//https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
        {
            return nums[0];
        }
        vector<int> res(n,0);
        res[1] = nums[0];
        for(int i=2;i<n;i++)
        {
            res[i] = max(res[i-1],res[i-2]+nums[i-1]);
        }
        int m1 = res[n-1];
        for(int i=0;i<n;i++)
        {
            res[i] = 0;
        }
        res[1] = nums[1];
        for(int i=2;i<n;i++)
        {
            res[i] = max(res[i-1],res[i-2]+nums[i]);
        }
        return max(m1,res[n-1]);
    }
};

/*
Logic:
-> Since the last and first house are connected, then we cant pick them both together
-> So take 2 cases and apply the solution of House Robber with the first case being first house selected so remove last element from the array and calculate the max
-> The next case being first house being dropped and last house included. Calculate the max and return the maximum of both of the previous answers
-> Adjust the indices of the res array closely and carefully
*/
