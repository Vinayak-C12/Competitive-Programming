//Leetcode - 3sum - Medium
//https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if(n<3)
        {
            return res;
        }
        sort(nums.begin(),nums.end());
        //Selecting 1 element and then using pair sum using 2 pointers to find the other 2 nos
        for(int i = 0;i<n-2;i++)
        {
            //Bcoz if you start with positive no sum of 3 cant be 0
            if(nums[i]>0)
            {
                break;
            }
            //To avoid duplicates
            if(i>0&&nums[i-1]==nums[i])
            {
                continue;
            }
            //Pair sum
            int j = i+1;
            int k = n-1;
            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<0)
                {
                    j++;
                }
                else if(sum>0)
                {
                    k--;
                }
                else
                {
                    res.push_back({nums[i],nums[j],nums[k]});
                    //Avoid duplicate nad updation of indices
                    while(j<k&&nums[j]==nums[j+1])
                    {
                        j++;
                    }
                    j++;
                    while(j<k&&nums[k-1]==nums[k])
                    {
                        k--;
                    }
                    k--;
                }
            }
        }
        return res;
        
    }
};
