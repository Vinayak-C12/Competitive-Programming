//Leetcode - Next Greater Element - Easy
//https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int,int> um;
        stack<int> s;
        vector<int> res;
        for(int i=m-1;i>=0;i--) // Using map to create the mapping of next greater element using stack 
        {
            while(!s.empty() && s.top()<=nums2[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                um[nums2[i]] = -1;
            }
            else
            {
                um[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
        for(int i=0;i<n;i++) // Filling the next greater element by using the map
        {
            res.push_back(um[nums1[i]]);
        }
        return res;
    }
};
