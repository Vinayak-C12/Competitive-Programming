//Leetcode - IPO - Hard
//https://leetcode.com/problems/ipo/?envType=daily-question&envId=2024-06-15

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> project;
        int n = profits.size();
        for(int i=0;i<n;i++)
        {
            project.emplace_back(capital[i],profits[i]);
        }
        sort(project.begin(),project.end());
        priority_queue<int> pq;
        int i=0;
        for(int j=0;j<k;j++) // As only k projects can be done
        {
            while(i<n && project[i].first<=w)// Add all the projects that can be done
            {
                pq.push(project[i].second);
                i++;
            }
            if(pq.empty())
            {
                break;
            }
            w += pq.top(); // Proj with max profit
            pq.pop();
        }
        return w;
    }
};
