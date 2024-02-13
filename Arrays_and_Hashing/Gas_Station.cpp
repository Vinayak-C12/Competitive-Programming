//LeetCode - Gas Station - Medium
//https://leetcode.com/problems/gas-station/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = gas.size();
        int idx = 0;
        int sum = 0;
        int idx_sum = 0;
        for(int i =0;i<n;i++)
        {
            sum += gas[i] - cost[i];
            idx_sum += gas[i] - cost[i];
            if(idx_sum<0)
            {
                idx = i+1;;
                idx_sum = 0;
            }
        }
        if(sum<0)
        {
            return -1;
        }
        else
        {
            return idx;
        }
    }
};
