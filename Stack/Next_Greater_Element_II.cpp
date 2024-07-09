//Leetcode - Next Greater Element II - Medium
//https://leetcode.com/problems/next-greater-element-ii/description/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,-1);
        stack<int> stk;
        for(int i=2*n-1;i>=0;i--)
        {
            while(!stk.empty() && stk.top()<=nums[i%n])
            {
                stk.pop();
            }
            if(!stk.empty() && i<n)  // The case where we find the next greater element
            {
                res[i] = stk.top();
            }
            stk.push(nums[i%n]);
        }
        return res;
    }
};

// The variation lies in the fact that the array is circular which basically means the length will be 2*n coz we will be visiting the element circularly until we reach the initial element to find the next greater element. So just initialise i to 2*n - 1 and take i%n and the rest should be the same as next greater element I and will work
