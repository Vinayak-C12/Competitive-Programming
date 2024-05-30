//Gfg - Longest subarray with sum K - Striver - Medium
//https://takeuforward.org/arrays/longest-subarray-with-sum-k-postives-and-negatives/

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int sum = 0;
        int len =0;
        unordered_map<int,int> presum; // A hashmap to maintain all the prefix sum
        for(int i=0;i<N;i++)
        {
            sum += A[i]; // Go on adding the array element sum to the sum
            if(sum == K)
            {
                len = max(len,i+1);
            }
            int rem = sum - K; // Basically when the sum is greater than k and u still wan to find a subarray with sum equal to K. So at this point sum will be > K and we find the prefix sum whose value will be sum - K so that the subarray sum will be K. Next update the length of this subarray
            if(presum.find(rem) != presum.end())
            {
                int l = i - presum[rem];
                len = max(len,l);
            }
            
            if(presum.find(sum) == presum.end()) // Update the prefix sum map. And we hav to do this coz of multiple update and we need the max length of subarray. Ex. K = 3 array - 2 0 0 3 prefix sum at 0,1,2 is 3. but for max length of subarray we need the prefix index value as 0, So that we get subaaray len as 3 - 0 = 3 which is the max value. if we directly push value into hashmap the value presum[2] = 2 instead of presum[2] = 0, which will make the len fo subbaray small
            {
                presum[sum] = i;
            }
        }
        return len;
    } 

};
