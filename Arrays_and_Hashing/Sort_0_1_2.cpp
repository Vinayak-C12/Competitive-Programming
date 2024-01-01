//Code-Studio - Sort 0,1,2 - Easy
//https://www.codingninjas.com/studio/problems/631055?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   unordered_map<int,int> um;
   for(int i=0;i<n;i++)
   {
      um[arr[i]]++;
   }
   int i = 0;
   while(um[0]--)
   {
      arr[i++]=0;
   }
   while(um[1]--)
   {
      arr[i++]=1;
   }
   while(um[2]--)
   {
      arr[i++]=2;
   }
}
