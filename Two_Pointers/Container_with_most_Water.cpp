#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int result=0;
        int i=0;
        int j=height.size()-1;
        while(i<j)
        {
           int w=j-i;
           int h=min(height[i],height[j]);
            int area=w*h;
            result=max(result,area);
           if(height[i]<=height[j])
           {
               i++;
           }
            else
            {
                j--;
            }
        }
        return result;
    }
};

int main()
{
Solution sol;
vector<int> height = {1,8,6,2,5,4,8,3,7};
int res=sol.maxArea(height);
cout<<res<<endl;
}
