//Geeksforgeeks - Number of occurences - Medium
//https://takeuforward.org/data-structure/count-occurrences-in-sorted-array/

class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
        int l=0,r=n-1;
        int s=-1,e=-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(arr[m]==x)
            {
                s=m;
                r=m-1;
            }
            else if(arr[m]<x)
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        l=0;
        r=n-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(arr[m]==x)
            {
                e=m;
                l=m+1;
            }
            else if(arr[m]<x)
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        if(s==-1)
        {
            return 0;
        }
        return e-s+1;
	}
};

/*
LOGIC:
->Find the first and last occurence of the number
->return e-s+1 if s is not -1(does not exist)
*/
