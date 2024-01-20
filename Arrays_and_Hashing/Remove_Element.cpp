//Leetcode - Remove Element - Easy
//https://leetcode.com/problems/remove-element/description/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
         std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = nums.size();

        int i = 0;

        while (i < n) {
            if (nums[i] == val) {
                nums.erase(nums.begin() + i);
                n--; 
            } else {
                i++; 
            }
        }

        return nums.size();
    }
};

