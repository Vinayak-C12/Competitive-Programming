//LeeCode - Divide array into Arrays with Max Difference -  Medium
//https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/?source=submission-ac

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {        
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);       
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i<nums.size();i=i+3)
        {
            if(nums[i+1]-nums[i]>k || nums[i+2]-nums[i]>k)
            {
                return res;
            }
        }
        res.resize(n/3,vector<int>(3));
        for(int i = 0;i<nums.size();i++)
        {
            res[i/3][i%3] = nums[i];
        }
        return res;
    }
};
