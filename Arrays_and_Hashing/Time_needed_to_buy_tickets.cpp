//Leetcode - Time needed to buy tickets - Easy
//https://leetcode.com/problems/time-needed-to-buy-tickets/description/

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        int n = tickets.size();
        int key = tickets[k];
        for(int i=0;i<=k;i++)
        {
            time += min(tickets[i], key);
        }
        key--;
        for(int i = k+1;i<n;i++)//Bcoz after k we dont need to count if they r greater than key. So decrease the count by 1
        {
            time += min(tickets[i],key);
        }
        return time;
    }
};
