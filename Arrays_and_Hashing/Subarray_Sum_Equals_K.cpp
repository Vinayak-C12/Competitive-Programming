//Leetcode - Subarray Sum Equals K - Medium
//https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = nums.size();
        unordered_map<int,int> um;
        um[0] = 1;//initialisation to indicate a 0 sum subarray exists before
        int res = 0;
        int cursum = 0;
        for(int i = 0;i<n;i++)
        {
            cursum += nums[i];// Calculating the subarray sum till now
            int diff = cursum - k;// Take diff between the cursum and k(target)
            if(um.find(diff) != um.end())// If it exits add that count to the res
            {
                res += um[diff];
            }
            um[cursum]++;// Update the presence of this prefix sum
        }
        return res;

    }
};
