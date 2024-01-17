//Leetcode - Longest Repeating Character Replacement - Medium
//https://leetcode.com/problems/longest-repeating-character-replacement/description/

class Solution {
public:
    int characterReplacement(string s, int k) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = s.size();
        int i = 0;
        int j = 0;
        vector<int> count(26);
        int maxsize = 0;
        int res = 0;
        while(j<n)
        {
            count[s[j]-'A']++;
            maxsize = max(maxsize,count[s[j]-'A']);
            if(j-i+1-maxsize>k)
            {
                count[s[i]-'A']--;
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};
