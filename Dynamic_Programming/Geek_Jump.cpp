//GeeksforGeeks - Geek Jump - Easy
//https://www.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump/

class Solution {
public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> res(n,0);
        res[0] = 0;
        if(n==1)
        {
            return 0;
        }
        res[1] = abs(height[1]-height[0]);
        for(int i=2;i<n;i++)
        {
            res[i] = min(res[i-1] + abs(height[i]-height[i-1]),res[i-2]+abs(height[i]-height[i-2]));
        }
        return res[n-1];
    }
};

