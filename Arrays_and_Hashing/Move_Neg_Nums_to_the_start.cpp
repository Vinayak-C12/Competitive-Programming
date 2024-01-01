//CodeStudio - Move negative numbers to the start - Easy
//https://parikh.club/parikh_twopointers2

#include <bits/stdc++.h> 
vector<int> separateNegativeAndPositive(vector<int> &nums){
    // Write your code here.
    int l=0;
    int n = nums.size();
    for(int i=0;i<n;i++)
    {
        if(nums[i]<0)
        {
            swap(nums[i],nums[l]);
            l++;
        }
    }
    return nums;

}
