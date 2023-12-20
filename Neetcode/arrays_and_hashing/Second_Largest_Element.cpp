//Coding Ninjas
//https://parikh.club/parikh_arrays_1

#include <bits/stdc++.h> 
int findSecondLargest(int n, vector<int> &arr)
{
    // Write your code here.
    int lar=0;
    int slar=-1;
    if(arr[0]>arr[1])
    {
        lar=arr[0];
        slar=arr[1];
    }
    else
    {
        lar=arr[1];
        slar=arr[0];
    }
    for(int i=2;i<n;i++)
    {
        if(arr[i]>lar)
        {
            slar=lar;
            lar=arr[i];
        }
        else
        if(arr[i]>slar&&arr[i]!=lar)
        {
            slar=arr[i];
        }
    }
    if(lar==slar)
    {
        return -1;
    }
    return slar;
}
