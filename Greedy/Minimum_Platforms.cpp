//GeeksforGeeks - Minimum Platforms - Medium
//https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n); // Note that here sort(arr.begin(),arr.end()) doesnt work for arr and dep as they r raw pointers and not vectors. It works only for vectors
    	sort(dep,dep+n); // So use the method given here by specifying the range as shown
    	int i=1;
    	int j = 0;
    	int maxi = 1;
    	int count = 1;
    	while(i<n && j<n)
    	{
    	    if(arr[i]<=dep[j]) //  Overlap so increase the platform count and increment i
    	    {
    	        count++;
    	        i++;
    	    }
    	    else // No overlap so reduce the extra platform and decrement count and increment j	
    	    {
    	        count--;
    	        j++;
    	    }
    	    maxi = max(maxi,count);
    	}
    	return maxi;
    }
};
/*
LOGIC:
-> Here the number of platforms can be ontained by identifying the number of conflicts or basically overlapping intervals of trains
-> So the brute force method would be to compare each train with the other to find the other trains which is O(N^2)
-> Overlapping in the sense the arrival and departure times of the other train or the stay duratiuon should fall in between the arrival and departure time of a given train under consideration. So here there will be 4 cases which u can figure out yourself
-> The solution here is to sort both the arr and dep arrays and check for overlap between arr and dep times
-> Use 2 pointers and if there is an overlap increment the count. The solution is basically the max number of overlap. Since it can change use maxi to store the maxi valure and then return it
*/
