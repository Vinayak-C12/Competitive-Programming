//Code-Studio - Easy
//https://www.codingninjas.com/studio/problems/make-unique-array_920329?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube

#include <bits/stdc++.h> 
int minElementsToRemove(vector<int> &arr)
{
	// Write your code here.
	unordered_map<int,int> mp;
	int count=0;
	int n=arr.size();
	for(int i=0;i<n;i++)
	{
		mp[arr[i]]++;
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		if(it->second!=0)
		{
			count++;
		}
	}
	return (n-count);
}
