//GeeksForGeeks - Boundary Traversal - Easy
//https://www.geeksforgeeks.org/problems/boundary-traversal-of-matrix-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        // code here
        int h = 0;
        int v = 1;
        vector<int> res;
        for(h = 0;h<m;h++)
        {
            res.push_back(matrix[0][h]);
        }
        for(v = 1;v<n;v++)
        {
            res.push_back(matrix[v][m-1]);
        }
        
        for(h = m-2;h>=0 && n>1;h--)
        {
            res.push_back(matrix[n-1][h]);
        }
        for(v = n-2;v>0 && m>1;v--)
        {
            res.push_back(matrix[v][0]);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
