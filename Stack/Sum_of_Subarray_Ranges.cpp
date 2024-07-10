//Leetocode - Sum of subarray Ranges - Medium
//https://leetcode.com/problems/sum-of-subarray-ranges/

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftMin(n, 0), rightMin(n, 0);
        vector<int> leftMax(n, 0), rightMax(n, 0);
        stack<int> minStack;
        stack<int> maxStack;

        for(int i = 0; i < n; i++) {
            while(!minStack.empty() && nums[minStack.top()] > nums[i])
                minStack.pop();

            leftMin[i] = minStack.empty() ? -1 : minStack.top();
            minStack.push(i);

            while(!maxStack.empty() && nums[maxStack.top()] < nums[i])
                maxStack.pop();

            leftMax[i] = maxStack.empty() ? -1: maxStack.top();
            maxStack.push(i);
        }

        minStack = stack<int>();
        maxStack = stack<int>();

        for(int i = n-1; i >= 0; i--) {
            while(!minStack.empty() && nums[minStack.top()] >= nums[i])
                minStack.pop();

            rightMin[i] = minStack.empty() ? n : minStack.top();
            minStack.push(i);

            while(!maxStack.empty() && nums[maxStack.top()] <= nums[i])
                maxStack.pop();

            rightMax[i] = maxStack.empty() ? n: maxStack.top();
            maxStack.push(i);
        }

        long long sumOfMaxes = 0, sumOfMins = 0;

        for(int i = 0; i < n; i++) {
            sumOfMaxes += (long long)nums[i]*(i-leftMax[i])*(rightMax[i]-i);
            sumOfMins += (long long)nums[i]*(i-leftMin[i])*(rightMin[i]-i);
        }

        return sumOfMaxes - sumOfMins;
    }
};

/*
LOGIC:
->The intuition in this questions lies in the fact that we use monotonic stack
->So a range in a subbarray basically means we add the max element and subtract the min element
->By using the monotonic stack we can find the next element min to the right and left and next element max to the right the left
->And by using this difference between the indices of i and left[i] and right[i] with respect to max and min we get the number of subarrays in which ith index will be the smallest or the largest element as next element min or max basically signifies no other element bigger or smaller exists till the given index
->Using this logic the number of subarrays where ith element gets to the min element will be (i-leftMin[i])*(rightMin[i]-i) and we subtract the nums[i] these many times
->Similarly use the same logic for max element but the max element will be added
*/

