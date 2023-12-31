//Leetcode - Element appearing more than 25%
//https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int i =0;
        while(i<n)
        {
            int len = 1;
            while(i<n-1&&arr[i]==arr[i+1])
            {
                len = len+1;
                i++;
            }
            if(len>n/4)
            {
                return arr[i];
            }
            i++;
        }
        return 0;
        
    }
    
};
