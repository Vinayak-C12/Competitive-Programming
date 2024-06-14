//Leetcode - Continuous Subarray Sum Divisible by K - Medium
//https://leetcode.com/problems/continuous-subarray-sum/description/?envType=daily-question&envId=2024-06-08

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> um;
        um[0]=-1;// If the subarray includes the first element 
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            int rem = sum%k;
            if(um.find(rem) != um.end()) // Same as subarray sum but only difference being that we r hashing the reminder instead of the sum
            {
                if(i-um[rem]>=2)
                {
                    return true;
                }
            }
            else
            {
                um[rem]=i;
            }
        }
        return false;
    }
};


