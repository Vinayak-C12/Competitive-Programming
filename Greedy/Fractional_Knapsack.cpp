//GeeksforGeeks - Fractional Knapsack - Medium
//https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        priority_queue<pair<double,pair<int,int>>> pq;
        for(int i=0;i<n;i++)
        {
            double valuePerWeight = (double) arr[i].value / arr[i].weight; // Explicitly need to use duble coz int/int is int
            pq.push({valuePerWeight, {arr[i].value, arr[i].weight}});
        }
        int wei = 0;
        double profit = 0;
        while(!pq.empty() && wei<w)
        {
            int iv = pq.top().second.first;
            int iw = pq.top().second.second;
            pq.pop();
            if(wei+iw<=w)
            {
                profit += iv;
                wei += iw;
            }
            else
            {
                int rem = w-wei;
                profit += iv*((double)rem/iw); // Explicitly use double for the same reason
                wei = w;
                break;
            }
        }
        return profit;
    }
};

