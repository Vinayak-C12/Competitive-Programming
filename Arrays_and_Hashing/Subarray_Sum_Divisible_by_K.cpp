//Leetcode - Subarray Sums divisible by K - Medium
//https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = nums.size();
        unordered_map<int,int> um;
        int sum = 0;
        int rem = 0;
        int ans = 0;
        um[0]=1;
        for(int i =0 ;i<n;i++)
        {
            sum += nums[i];
            rem = sum%k;
            if(rem<0)
            {
                rem+=k;
            }
            if(um.find(rem)!=um.end())
            {
                ans+=um[rem];
                um[rem]++;
            }
            else
            {
                um[rem]=1;
            }
        }
        return ans;
    }
};
