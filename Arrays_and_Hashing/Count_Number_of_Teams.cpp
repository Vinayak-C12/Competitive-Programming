//Leetcode - Count Number of Teams - Medium
//https://leetcode.com/problems/count-number-of-teams/description/?envType=daily-question&envId=2024-07-29

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count = 0;
        for(int i=1;i<n;i++)
        {
            int ls=0,rb=0; // Ascending order
            for(int j=0;j<i;j++)
            {
                if(rating[j]<rating[i]) // Finding the number of elements smaller to the left
                {
                    ls++;
                }
            }
            for(int j=i+1;j<n;j++) // Finding the number of elemenst larger to the right
            {
                if(rating[i]<rating[j])
                {
                    rb++;
                }
            }
            count += ls*rb; // Add their product to the count to get the pairs
            int lb=0,rs=0;
            lb = i-ls; // There are i elements to the left and if ls elements are smaller then the rest hav to be larger. So lb = i-ls;
            rs = n-i-1-rb; // There are n-i-1 elements to the right and if rb are larger the rest hav to be smaller.S o rs = n-i-1-rb;
            count += lb*rs;
        }
        return count;
    }
};

/*
->Logic:
-> The idea is to iterate the array and check if any element can be the middle element ie find the number of elements smaller and bigger than i to the left and right
-> Then first case is ascending order when u add the product of number of elements smaller than i to the left and the number of elements larger than i to the right
-> The second case is descending order when u add the product of number of elements greater than i to the left and the number of elemenst lesser than i to the right
-> Sum of all these is the answer
*/
