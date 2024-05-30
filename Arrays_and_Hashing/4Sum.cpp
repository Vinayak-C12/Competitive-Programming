//Leetcode - 4Sum - Medium
//https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        if(n<4)
        {
            return res;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) // To skip duplicates
            {
                continue;
            }
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1 && nums[j]==nums[j-1]) // To skip duplicates and j>i+1 and not i coz j>i will allow duplicates and thus we use i+1(similar to i>0)
                {
                    continue;
                }
                int k=j+1;
                int m=n-1;
                while(k<m)
                {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[m];
                    if(sum>target)
                    {
                        m--;
                    }
                    else if(sum<target)
                    {
                        k++;
                    }
                    else
                    {
                        res.push_back({nums[i],nums[j],nums[k],nums[m]});
                        while(k<m && nums[k]==nums[k+1])
                        {
                            k++;
                        }
                        k++;
                        while(k<m && nums[m]==nums[m-1])
                        {
                            m--;
                        }
                        m--;
                    }
                }
            }
        }
        return res;
    }
};

/*
LOGIC:
->It is similar to 3sum. It has 4 pointers of which 2 are moving(k,m) and 2 are fixed(i,j)
->Start sorting the array and fixing the first element
->Then it becomes 3sum with the only variation being that the target here is target instead of 0
->The sum is calculated in a slighlt different manner in order to avoid the overflow
*/
