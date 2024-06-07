//LeetCode - Subarray with given XOR - Medium
//https://www.interviewbit.com/problems/subarray-with-given-xor/

#include<bits/stdc++.h>
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int cnt=0;
    unordered_map<int,int> um;
    um[0]=1;
    int xorr=0;
    for(int i=0;i<n;i++)
    {
        xorr ^=A[i];
        int x = xorr^B;
        cnt+=um[x];
        um[xorr]++;
    }
    return cnt;
}

/*
LOGIC:
->Using hashmap
->If a subarray has a prefix xor as xr
->And there is another subarray whose xor is k and is after index i
->Then the xor of the subarray till index i will be xr^k
->This is because xr^k^k = xr
->Therefore we hash this prefix xor value and use it to count the number of subarrays
