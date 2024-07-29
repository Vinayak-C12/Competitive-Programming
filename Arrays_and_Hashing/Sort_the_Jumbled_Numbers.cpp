//Leetcode - Sort the Jumbled Numbers - Medium
//https://leetcode.com/problems/sort-the-jumbled-numbers/description/?envType=daily-question&envId=2024-07-24

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> um;
        map<int,vector<int>> order;
        for(int i=0;i<mapping.size();i++)
        {
            um[i] = mapping[i];
        }
        for(int num:nums)
        {
            int mul = 1;
            int ans = 0;
            int temp = num;
            if(temp == 0) // Edge case for handling 0 as while loop doesnt accept it
            {
                ans = um[0];
            }
            else
            {
            while(temp>0)
            {
                int dig = temp%10;
                ans = ans + mul*um[dig];
                mul *= 10;
                temp /= 10;
            }
            }
            order[ans].push_back(num);
        }
        for(auto it=order.begin();it!=order.end();it++)
        {
            vector<int> temp = it->second;
            for(int i=0;i<temp.size();i++)
            {
                res.push_back(temp[i]);
            }
        }
        return res;
    }
};
