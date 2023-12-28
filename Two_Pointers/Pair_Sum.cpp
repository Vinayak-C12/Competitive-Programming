//Code-Studio - Pair Sum(Count the number of pairs having sum==target) - Easy
//https://www.codingninjas.com/studio/problems/pair-sum_1171154?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube

#include <bits/stdc++.h> 
int pairSum(vector<int> &arr, int n, int target){
	// Write your code here.
	int i=0;
	int j=n-1;
	int count=-1;
	while(i<j)
	{
		if(arr[i]+arr[j]==target)
		{
			count++;
			i++;
			j--;
		}
		else if(arr[i]+arr[j]<target)
		{
			i++;
		}
		else
		{
			j--;
		}
	}
	if(count!=-1)
	{
		return count+1;
	}
	else
	{
		return count;
	}

}
