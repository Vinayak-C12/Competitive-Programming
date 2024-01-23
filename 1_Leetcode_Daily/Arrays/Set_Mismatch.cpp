//Leetcode - Set Mismatch - Easy
//https://leetcode.com/problems/set-mismatch/description/?envType=daily-question&envId=2024-01-22

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = nums.size();
        int missing = 0;
        int duplicate = 0;
        vector<int> count(n+1,0);
        for(int i = 0;i<n;i++)
        {
            count[nums[i]]++;
        }
        for(int i = 1;i<n+1;i++)
        {
            if(count[i] == 0)
            {
                missing = i;
            }
            if(count[i] == 2)
            {
                duplicate = i;
            }
        }
        return {duplicate,missing};
        
        
    }
};
