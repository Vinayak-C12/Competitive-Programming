//leetcode : H-index
//https://leetcode.com/problems/h-index/submissions/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        sort(citations.begin(),citations.end());
        int s=0;
        int e=n-1;
        int ans=0;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(citations[mid]>=n-mid)
            {
                ans=max(ans,n-mid);
                e=mid-1;
            }
            else
                s=mid+1;
        }
        return ans;
    }
};
