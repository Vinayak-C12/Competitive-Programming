//Code-Studio - Easy - Intersection of 2 arrays
//https://www.codingninjas.com/studio/problems/intersection-of-2-arrays_1082149?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube

#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
	int i=0;
	int j=0;
	vector<int> res;
	while(i<n && j<m)
	{
		if(arr1[i]==arr2[j])
		{
			res.push_back(arr1[i]);
			i++;
			j++;
		}
		else if(arr1[i]<arr2[j])
		{
			i++;
		}
		else
		{
			j++;
		}
	}
	return res;
}
