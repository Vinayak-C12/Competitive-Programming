//Code-Studio - Moderate - Maximum_Subaaray_Sum(Kadane's Algo)
//https://www.codingninjas.com/studio/problems/630526?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube

long long maxSubarraySum(vector<int> arr, int n)
{
    // Write your code here.
    long long max_sum=INT_MIN;
    long long curr_sum=0;
    for(int i=0;i<n;i++)
    {
        curr_sum=curr_sum+arr[i];
        if(max_sum<curr_sum)
        {
            max_sum=curr_sum;
        }
        if(curr_sum<0)
        {
            curr_sum=0;
        }
    }
    if(max_sum<0)
    {
        return 0;
    }
    else
    {
        return max_sum;
    }
 
}
