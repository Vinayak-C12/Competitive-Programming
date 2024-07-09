//Leetcode - Average Waiting Time - Medium
//https://leetcode.com/problems/average-waiting-time/description/?envType=daily-question&envId=2024-07-09

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int time =customers[0][0];
        double wait = 0;
        for(int i=0;i<n;i++)
        {
            if(time>=customers[i][0]) // To check if the customer has been waiting form before
            {
                time += customers[i][1];
                wait += time - customers[i][0];
            }
            else // If the order arrives later then the waiting for the customer will just be the time taken to make the dish
            {
                time = customers[i][0] + customers[i][1];
                wait += customers[i][1];
            }
        }
        return wait/n;
    }
};
