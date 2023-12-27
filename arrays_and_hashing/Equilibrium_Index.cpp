//Code Studio - Equlbrium Index
//https://www.codingninjas.com/studio/problems/equilibrium-index_893014?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube
#include <bits/stdc++.h> 
int findEquilibriumIndex(vector<int> &arr) {
    // Write your code here.
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
    }
    int ls = 0;
    int rs = 0;
    for (int i = 0; i < n; i++) {
        rs = sum - ls - arr[i]; // Adjust rs before updating ls
        if (ls == rs) {
            return i;
        }
        ls = ls + arr[i];
    }
    /*for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            rs=sum-arr[0];
        }
        else if(i==n-1)
        {
            ls=ls+arr[i-1];
            rs=0;
        }
        else
        {
          ls=ls+arr[i-1];
          rs=rs-arr[i];
        }
        if(ls==rs)
        {
            return i;
        }
    }
    */
    return -1;
}
