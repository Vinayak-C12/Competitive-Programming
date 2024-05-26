//LeetCode - Find the Number of Distinct Colors Among the Balls - Medium
//https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int m = queries.size();
        unordered_map<int,int> color,count;
        vector<int> res(m);
        for(int i=0;i<m;i++)
        {
            if(color.find(queries[i][0]) != color.end())//Ball is already colored. So decrease the color frequency of old color
            {
                count[color[queries[i][0]]]--;
                if(count[color[queries[i][0]]] == 0)// Color doesnt exist so remove it
                {
                    count.erase(color[queries[i][0]]);
                }
            }
            color[queries[i][0]] = queries[i][1]; // Update the new color and frequency
            count[queries[i][1]]++;
            res[i] = count.size();
        }
        return res;
    }
};
