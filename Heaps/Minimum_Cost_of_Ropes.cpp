//GeeksForGeeks - Minimum cost of ropes - Easy
//https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(long long i =0;i<n;i++)
        {
            pq.push(arr[i]);
        }
        long long sum = 0;
        while(pq.size()>=2)
        {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            pq.push(a+b);
            sum += a+b;
        }
        return sum;
    }
};
