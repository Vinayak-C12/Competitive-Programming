//LeetCode - First index of occurence in a String - Easy
//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int strStr(string haystack, string needle) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int len = needle.size();
        for(int  i=0;i<haystack.size();i++)
        {
            if(needle == haystack.substr(i,len))
            {
                return i;
            }
        }
        return -1;
    }
};
