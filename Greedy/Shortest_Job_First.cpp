//GeeksforGeeks - Shortest Job First - Medium
//https://www.geeksforgeeks.org/problems/shortest-job-first/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-job-first

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        long long res = 0;
        int n = bt.size();
        sort(bt.begin(),bt.end());
        for(int i=0;i<n;i++) // Sort and count the number of times each element will be added and add it by that many times
        {
            res += bt[i]*(n-i-1);
        }
        res = res/n;
        return res;
    }
};

class Solution {
  public:
    long long solve(vector<int>& bt) { // Solution 2 using direct SJF algo idea
        // code here
        long long tot = 0;
        int n = bt.size();
        long long wait = 0;
        sort(bt.begin(),bt.end());
        for(int i=0;i<n;i++)
        {
            wait += tot;
            tot += bt[i];
        }
        wait = wait/n;
        return wait;
    }
};
