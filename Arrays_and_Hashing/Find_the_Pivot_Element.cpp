//LeetCode - Find the pivot Integer - Easy
//https://leetcode.com/problems/find-the-pivot-integer/description/

class Solution {
public:
    int pivotInteger(int n) {
        vector<int> l(n,0);
        vector<int> r(n,0);
        l[0] = 1;
        r[n-1] = n;
        for(int i=1;i<n;i++)
        {
            l[i] = l[i-1] + i+1;
        }
        for(int  i=n-2;i>=0;i--)
        {
            r[i] = r[i+1] + i+1;
        }
        for(int i=0;i<n;i++)
        {
            if(l[i] == r[i])
            {
                return i+1;
            }
        }
        return -1;
    }
};
