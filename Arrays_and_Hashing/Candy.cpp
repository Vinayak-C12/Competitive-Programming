//LeetCode - Candy - Hard
//https://leetcode.com/problems/candy/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int candy(vector<int>& ratings) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = ratings.size();
        vector<int> candy(n,1); // Bcoz atleast 1 candy must be given initialise by 1
        int sum = 0;
        for(int i = 0;i<n-1;i++)
        {
            if(ratings[i]>ratings[i+1])
            {
                candy[i] = candy[i+1]+1; // As we need the min number just give 1 candy more
            }else if(ratings[i]<ratings[i+1])
            {
                candy[i+1] = candy[i]+1;
            }
        }
        // The second loop is needed bcoz the above loop doesnt account the possiblity of continiously decreasing rating values Ex 1 2 87 87 87 2 1
        for(int i = n-1;i>=1;i--)
        {
            if(ratings[i]<ratings[i-1] && candy[i]>=candy[i-1])
            {
                candy[i-1] = candy[i]+1;
            }else if(ratings[i]>ratings[i-1] && candy[i]<=candy[i-1]) // Test case: 1 3 4 5 2  Bcoz of loop 1 the candy[3] = candy[4] + 1 = 1+1 =2 instead of 4
            {
                candy[i] = candy[i-1] +1;
            }
        }
        for(int i =0;i<n;i++)
        {
            sum += candy[i];
        }
        return sum;
    }
};


// Cleaner Code :  Logic first make sure all the left neighbours have less candies then in the sececond pass make sure the right neighbours have less candies
class Solution {
public:
    int candy(vector<int>& ratings) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = ratings.size();
        vector<int> candy(n,1);
        int sum = 0;
        for(int i = 1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                candy[i] = candy[i-1]+1;
            }
        }
        for(int i = n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                candy[i] = max(candy[i],candy[i+1]+1);// Test Case : 1 3 4 5 2   candy[3] = max(4,1+1)
            }
        }
        for(int i = 0;i<n;i++)
        {
            sum += candy[i];
        }
        return sum;
    }
};
