//LeetCode - Polygon with Longest Perimeter - Easy
//https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/?envType=daily-question&envId=2024-02-15

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        long long sum = 0;
        sort(nums.begin(),nums.end());
        sum = nums[0] + nums[1];
        for(int i = 2;i<n;i++)
        {
            if(sum > nums[i])
            {
                res = sum + nums[i];
            }
            sum += nums[i];
        }
        if(res == 0)
        {
            return -1;
        }
        else
        {
            return res;
        }
    }
};
