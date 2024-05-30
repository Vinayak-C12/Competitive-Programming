//Leetcode - Next Permutation - Medium
//https://leetcode.com/problems/next-permutation/description/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        int i2 = 0;
        int s = INT_MAX;
        for(int i = n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                idx = i;
                break;
            }
        }
        if(idx == -1)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            for(int i=idx+1;i<n;i++)
            {
                if(nums[i]>nums[idx])
                {
                    if(nums[i]<s)
                    {
                        i2 = i;
                    }
                }
            }
            swap(nums[idx],nums[i2]);
            reverse(nums.begin()+idx+1,nums.end());
        }
    }
};

LOGIC:

First we need to find the breaking point to find the next permuatation ie start from the end and find  the first index where a[i]<a[i+1]
->Next if there is no break point that means the array is in the last permutation so reverse it get the next permuataion
->if we hav the breaking point then find the index of the smallest number greater than a[i](i-break point) coz that number will be swapped with i. After that sawp it with a[i]
->Lastly reverse the array from i+1 to a.end()
