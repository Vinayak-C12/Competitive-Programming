//GeeksForGeeks - Adding Array Elements - Easy
//https://www.geeksforgeeks.org/problems/adding-array-element4756/1

class Solution{
  public:
    int minOperations(int arr[], int n, int k) {
        // code here
        priority_queue <int, vector<int>, greater<int>> pq;
        for(int i =0;i<n;i++)
        {
            pq.push(arr[i]);
        }
        int count = 0;
        while(pq.top()<k)
        {
            int a = pq.top();
            pq.pop();
            if(pq.empty())
            {
                return -1;
            }
            int b = pq.top();
            pq.pop();
            pq.push(a+b);
            count++;
        }
        return count;
    }
};



  
