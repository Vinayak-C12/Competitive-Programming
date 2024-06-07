//Leetcode - Merge Intervals - Medium
//https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        res.push_back(intervals[0]);
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<=res.back()[1])
            {
                res.back()[1] = max(intervals[i][1],res.back()[1]);// To get the biggest interval as the end time of the current inetrval might be bigger
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

/*
LOGIC:
->First sort the array and initialise the res array with the first element
->Next traverse the array and check if a given interval can be merged with the previous one ie if the start of the current interval is less tahn or equal to the end of the previous interval
->If it is merge it with the interval or else just add it to the res array
*/
