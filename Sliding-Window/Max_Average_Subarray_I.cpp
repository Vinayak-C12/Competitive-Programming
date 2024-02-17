//LeetCode - Max Average Subarray I - Easy
//https://leetcode.com/problems/maximum-average-subarray-i/description/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        int n = nums.size();
        int sum = 0;
        int temp = 0;
        for(int i=0;i<k;i++)
        {
            temp += nums[i];
        }
        sum = temp;
        for(int i=k;i<n;i++)
        {
            temp = temp + nums[i] - nums[i-k];
            sum = max(temp,sum);
        }
        return (double)sum/k;// Dont forget the typecasting
    }
};
