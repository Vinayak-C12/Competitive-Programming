//LeetCode - Summary Ranges - Easy
//https://leetcode.com/problems/summary-ranges/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        int i = 0;
        while(i<n)
        {
            int start = i;
            int end =i;
            while(end+1<n && nums[end+1] == nums[end] + 1)
            {
                end++;
            }
            if(start != end)
            {
                string temp ="";
                temp += to_string(nums[start])+"->"+to_string(nums[end]);
                res.push_back(temp);
            }
            else
            {
                res.push_back(to_string(nums[start]));
            }
            i = end + 1;
        }
        return res;
    }
};
