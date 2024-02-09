//GeeksForGeeks - Chocolate Distribution Problem - Easy
//https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(),a.end());
    long long mini = INT_MAX;
    for(int i = m-1;i<n;i++)
    {
        mini = min(mini , a[i] - a[i-m+1]);
    }
    return mini;
    }   
};
