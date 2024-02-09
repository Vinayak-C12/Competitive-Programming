//Leetcode - Longest Common Prefix - Easy
//https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
       int m = INT_MAX;
       string res = "";
       for(auto str : strs)
       {
           int l = str.size();
           m = min(m,l);
       } 
       for(int i = 0;i<m;i++)
       {
           char c = strs[0][i];
           int flag = 1;
           for(int j = 1;j<strs.size();j++)
           {
               if(strs[j][i] == c)
               {
                   flag = 1;
                   continue;
               }
               else
               {
                   flag = 0;
                   break;
               }
           }
           if(flag == 1)
           {
               res += c;
           }
           else
           {
               break;
           }
       }
       return res;
    }
};
