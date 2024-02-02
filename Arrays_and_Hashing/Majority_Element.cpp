//LeetCode - Majority Element - Easy
//https://leetcode.com/problems/majority-element/description/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int major = 0;
        int count = 0;
        for(auto num : nums)
        {
            if(count == 0)
            {
                major = num;
                count = 1;
            }else if(major == num)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return major;
    }
};
// BOYER MOORE MAJORITY VOTING ALGO  TIME - O(N) SPACE - O(1)
