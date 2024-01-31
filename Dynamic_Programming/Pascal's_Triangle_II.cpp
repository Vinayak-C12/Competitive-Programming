//LeetCode - Pascal's Triangle II - Easy
//https://leetcode.com/problems/pascals-triangle-ii/description/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> res;
        for(int i = 0 ; i <= rowIndex;i++)
        {
            vector<int> temp(i+1 , 1);
            for(int j = 1; j<i;j++)
            {
                    temp[j] = res[j-1] + res[j];
            }
            res = temp;
        }
        return res;        
    }
};
