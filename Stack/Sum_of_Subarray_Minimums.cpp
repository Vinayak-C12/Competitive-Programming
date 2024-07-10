//Leetcode - Sum of Subarray Minimums - Medium
//https://leetcode.com/problems/sum-of-subarray-minimums/description/?envType=daily-question&envId=2024-01-20


class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> left(n,-1);
        vector<int> right(n,n);
        stack<int> s;
        long long sum = 0;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && arr[s.top()]>=arr[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                left[i] = s.top();
            }
            s.push(i);
        }
        s = stack<int>();
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && arr[s.top()]>arr[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                right[i] = s.top();
            }
            s.push(i);
        }
        for(int i=0;i<n;i++)
        {
            sum += static_cast<long long> (i-left[i])*(right[i]-i)*arr[i]%MOD;
            sum %= MOD;
        }
        return sum;
    }
};

/*
LOGIC: 
->Using monotonic stack the keep track of the next smaller element ot the left and to the right
->Next that element will be added to the sum as many times as it occurs as the smallest element in the subarrays
->The number of subarrays ending at index i is i+1
*/
