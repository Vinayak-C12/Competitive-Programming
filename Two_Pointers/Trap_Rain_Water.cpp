#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) 
    {
        int i=0;
        int j=height.size()-1;
        int maxleft=height[i];
        int maxright=height[j];
        int result=0;
        while(i<j)
        {
            if(maxleft<=maxright)
            {
                i++;
                maxleft=max(maxleft,height[i]);
                result+=maxleft-height[i];
            }
            else
            {
                j--;
                maxright=max(maxright,height[j]);
                result+=maxright-height[j];
            }
            
        }
        return result;
        
    }
};

int main()
{
Solution sol;
vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
int res=sol.trap(height);
cout<<res<<endl;
}
