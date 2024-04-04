//Leetcode - Max Length of Concatenated String with Unique Characters - Medium
//https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/?envType=daily-question&envId=2024-01-23

class Solution {
public:
    int maxLength(vector<string>& arr) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> dp ={0}; // To store the bitmasks
        int res = 0;
        for(const string& s:arr)
        {
            int a = 0;
            int dup = 0;
            for(char c:s)
            {
                dup |= a & (1<<(c - 'a'));// Checking if the new charcter is a repeated cahracter in the string
                a |= 1<<(c - 'a'); // If not update the string bitmask
            }
            if(dup>0)// Means there was a repeated character
            {
                continue;
            }
            for(int i = dp.size()-1;i>=0;i--)
            {
                if((dp[i]&a)>0)// Repeated character
                    continue;
                dp.push_back(dp[i]|a);// Concatenation of bitmask
                res = max(res, __builtin_popcount(dp[i]|a));
            }
        }
        return res;
    }
};
