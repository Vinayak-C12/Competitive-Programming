//Leetcode - Unique Number of Occurences - Easy
//https://leetcode.com/problems/unique-number-of-occurrences/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = arr.size();
        unordered_map<int,int> um;
        unordered_set<int> us;
        for(int i = 0;i<n;i++)
        {
            um[arr[i]]++;
        }
        for(auto it = um.begin();it!=um.end();it++)
        {
            if(us.count(it->second)==1)
            {
                return false;
            }
            else
            {
                us.insert(it->second);
            }
        }
        return true;
    }
};
