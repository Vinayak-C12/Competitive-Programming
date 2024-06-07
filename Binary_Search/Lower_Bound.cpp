//Geeksforgeeks - Floor in a sorted array or lower bound - Easy
//https://takeuforward.org/arrays/implement-lower-bound-bs-2/

class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        int l = 0;
        int r = n-1;
        int ans =-1;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(v[m]<=x)
            {
                ans=m;
                l = m+1;
            }
            else
            {
                r = m-1;
            }
        }
        return ans;
    }
};
