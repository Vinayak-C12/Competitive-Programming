//Leetcode - Most Profit Assigning Work - Medium
//https://leetcode.com/problems/most-profit-assigning-work/description/?envType=daily-question&envId=2024-06-18

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> pro;
        int n = difficulty.size();
        int ans = 0;
        int best = 0;
        for(int i=0;i<n;i++)
        {
            pro.emplace_back(difficulty[i],profit[i]);
        }
        sort(pro.begin(),pro.end());
        sort(worker.begin(),worker.end());
        priority_queue<int> pq;
        int i = 0;
        for(int j=0;j<worker.size();j++)
        {
            while(i<n && pro[i].first<=worker[j])
            {
                best = max(best,pro[i].second);
                i++;
            }
            ans += best;
        }
        return ans;
    }
};

