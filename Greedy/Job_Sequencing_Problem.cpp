//GeeksforGeeks - Job Sequencing Problem - Medium
//https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr + n, [](Job &a, Job &b) {//Custom sorting to directly sort the objects in descending order. a and b are references to objects and it is lambda fn
            return a.profit > b.profit;
        });
        int maxi = arr[0].dead;
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi,arr[i].dead); // Finding the max deadline to which it can be pushed
        }
        vector<int> slot(maxi+1,-1); // Creating a slot array
        int count = 0;
        int pro = 0;
        for(int i=0;i<n;i++) // Iterate through each element and try to fit in the slot array . It works as it is in descending order
        {
            for(int j=arr[i].dead;j>0;j--) // Since each element can be done on any day from 1 to arr[i].dead
            {
                if(slot[j] == -1)
                {
                    slot[j] = i;
                    count++; // Increment count
                    pro += arr[i].profit; // add profit
                    break;
                }
            }
        }
        return {count,pro};
    } 
};
