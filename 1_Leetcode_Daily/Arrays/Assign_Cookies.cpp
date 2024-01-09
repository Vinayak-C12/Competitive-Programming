//Leetcode - Assign Cookies - Easy
//https://leetcode.com/problems/assign-cookies/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = s.size();
        int m = g.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j=0;
        while(i<m)
        {
            while(j<n&&g[i]>s[j])
                  {
                      j++;
                  }
            if(j==n)
            {
                break;
            }
            i++;
            j++;
        }
        return i;
}
};
