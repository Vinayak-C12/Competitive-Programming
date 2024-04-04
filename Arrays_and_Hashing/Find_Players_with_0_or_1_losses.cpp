//Leetcode - Find players with 0 or 1 losses
//https://leetcode.com/problems/find-players-with-zero-or-one-losses/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_map<int,int> loss;
        vector<int> zero;
        vector<int> one;
        vector<vector<int>> result;
        for(auto match : matches)
        {
            if(loss.find(match[0])==loss.end())
            {
                loss[match[0]]=0;
            }
            loss[match[1]]--;
        }
        for(auto it = loss.begin();it!=loss.end();it++)
        {
            if(it->second==0)
            {
                zero.push_back(it->first);
            }
            if(it->second==-1)
            {
                one.push_back(it->first);
            }
        }
        sort(zero.begin(),zero.end());
        sort(one.begin(),one.end());
        result.push_back(zero);
        result.push_back(one);
        return result;
        
    }
};
