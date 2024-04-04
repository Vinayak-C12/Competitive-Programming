//Leetcode - Determine if two Strings are close - Medium
//https://leetcode.com/problems/determine-if-two-strings-are-close/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> w1(26,0);
        vector<int> w2(26,0);
        if(m!=n)
        {
            return false;
        }
        for(auto c: word1)
        {
            w1[c-'a']++;
        }
        for(auto c: word2)
        {
            w2[c-'a']++;
        }
        for(int i =0;i<26;i++)
        {
            bool w1status = w1[i]>0;
            bool w2status = w2[i]>0;
            
            if(w1status == !w2status || !w1status==w2status)
            {
                return false;
            }
        }
        sort(w1.begin(),w1.end());
        sort(w2.begin(),w2.end());
        for(int i = 0;i<26;i++)
        {
            if(w1[i]!=w2[i])
            {
                return false;
            }
        }
        return true;
        
    }
};
