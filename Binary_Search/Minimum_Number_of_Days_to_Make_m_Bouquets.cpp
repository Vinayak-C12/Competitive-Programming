//Leetcode - Minimum Number of Days to Make m Bouquets - Medium - Striver
//https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 1;
        int r = *max_element(bloomDay.begin(),bloomDay.end());
        int count = INT_MAX;
        int n = bloomDay.size();
        long res = (long)m*(long)k; //Edge Case
        if(res > n)
        {
            return -1;
        }
        while(l<=r)
        {
            int mid = (l+r)/2;
            int i = 0;
            int temp = 0;
            while(i<n)
            {
                int len = 0;
                while(len<k && i+len<n && bloomDay[i+len]<=mid)
                {
                    len++;
                    if(len == k)
                    {
                        temp++;
                        break;
                    }
                }
                if(len == k)
                {
                    i = i+len;
                }
                else
                {
                    i = i+len+1;
                }
            }
            if(temp>=m)
            {
                count = min(count,mid);
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return count;
    }
};
