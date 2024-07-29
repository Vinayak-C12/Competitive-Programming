//Leetcode - Insert Interval - Medium
//https://leetcode.com/problems/insert-interval/description/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int a1 = newInterval[0],b1 = newInterval[1];
        vector<vector<int>> res;
        for(int i=0;i<n;i++)
        {
            int a2 = intervals[i][0],b2 = intervals[i][1];
            if(a2>b1) // It means this interval comes after the interval to be inserted. So directly add a1,b1 and then pass this a2,b2 further so that it will be inserted in the end
            {
                res.push_back({a1,b1});
                a1 = a2;
                b1 = b2;
            }
            else if(b2<a1) // No overlap so add directly
            {
                res.push_back({a2,b2});
            }
            else // Overlap
            {
                a1 = min(a1,a2);
                b1 = max(b1,b2);
            }
        }
        res.push_back({a1,b1}); // Adding the interval
        return res;
    }
};

/*
Logic:
-> We basically need to identify the intervals overlapping with the interval to be inserted and merge them and insert it to the result
-> The intervals before the start of the interval to be merged and after the end of the interval to be merged will be unaffected
-> Overlap doesnt occur when a2>b1 and b2<a1. So just insert those directly
-> For overlapping ones just keep track of min start and max end
-> Just directly insert that interval in the end
*/
