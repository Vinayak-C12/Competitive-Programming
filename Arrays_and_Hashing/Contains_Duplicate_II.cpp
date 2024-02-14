//LeetCode - Contains Duplicate II - Easy
//https://leetcode.com/problems/contains-duplicate-ii/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> um;
        for(int i=0;i<n;i++)
        {
            if(um.find(nums[i]) != um.end())
            {
                if(i - um[nums[i]]<=k)
                {
                    return true;
                }
                else
                {
                    um[nums[i]] =i;
                }
            }
            um[nums[i]] = i;
        }
        return false;
    }
};
