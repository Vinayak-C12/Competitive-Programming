//Leetcode - Permutation in a string - Medium
//https://leetcode.com/problems/permutation-in-string/description/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> count1(26,0);
        vector<int> count2(26,0);
        int n = s1.size();
        int m = s2.size();
        for(int i=0;i<n;i++)
        {
            count1[s1[i]-'a']++;
        }
        int l = 0;// Start of the string
        int r = n-1;// End of the string
        int len = 0;// Length of string or sliding window
        while(r<m)
        {
            while(len<n)
            {
                count2[s2[len+l]-'a']++;
                len++;
            }
            if(count1==count2)
            {
                return true;
            }
            else
            {
                count2[s2[l]-'a']--;
                len = len-1;
                r++;
                l++;
            }
        }
        return false;

    }
};
