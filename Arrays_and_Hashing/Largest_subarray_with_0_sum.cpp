//Geeksforgeeks - Largest subarray with 0 sum - Medium - Striver
//https://takeuforward.org/data-structure/length-of-the-longest-subarray-with-zero-sum/

class Solution{ // Similar to longest subarray with sum k where k is 0
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> um;
        int longest = 0;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += A[i];
            if(sum == 0)
            {
                longest = max(longest,i+1);
            }
            if(um.find(sum) != um.end()) // rem not needed as sum - k is sum only as k is 0
            {
                int len = i-um[sum];
                longest = max(len,longest);
            }
            if(um.find(sum) == um.end())
            {
                um[sum] = i;
            }
        }
        return longest;
    }
};
