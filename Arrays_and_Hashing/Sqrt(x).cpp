//Leetcode - Sqrt(x) - Easy
//https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
    int s =0;
    int e = x;
    long long int ans=0;
    if(x==0||x==1)
    {
        return x;
    }
    while(s<=e)
    {
        long long int mid = (s+e)/2;
        if(mid*mid<=x)
        {
            ans=mid;
            s=mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return ans;
    }
};


