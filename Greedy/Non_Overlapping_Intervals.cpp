//Leetcode - Non Overlapping Intervals - Medium
//https://leetcode.com/problems/non-overlapping-intervals/description/

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp); // Sorting based on end times

        int prev = 0; // To store index of prev interval
        int count = 1; // Number of intervals in the final array

        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= intervals[prev][1]){ // No overlap
                prev = i; // Add the interval to the array
                count++; // Increment count
            } 
        }
        return n - count; // This gives the number of intervals removed
    }
};
