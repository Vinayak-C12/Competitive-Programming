//Code-Studio - Easy - Symmetric Matrix
//https://www.codingninjas.com/studio/problems/matrix-is-symmetric_799361?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube

#include <bits/stdc++.h> 
bool isMatrixSymmetric(vector<vector<int>> matrix){
    // Write your code here. 
    int m = matrix.size();
    int n = matrix[0].size();
    int flag=1;
    for(int i = 0;i<m-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(matrix[i][j]!=matrix[j][i])
            {
                flag=0;
            }
        }
    }
    if(flag!=1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
