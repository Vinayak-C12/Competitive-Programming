//Leetcode -  Min Operations to empty the array - Medium
//https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> um;
        for(int i = 0;i<nums.size();i++)
        {
            um[nums[i]]++;
        }
        int ans = 0;
        for(auto it=um.begin();it!=um.end();it++)
        {
        //Logic : Try to remove in multiples of 3. If n%3 ==1 , that means 1 additional operation is needed...so add 2. Ex 10, op = 4 (3-2 + 2-2) (10+2)/3=4
        //If n%3 == 2 1 additional op is needed to remove 2 elements ... so do (n+2)/3 Ex 14 op=5(3-4 +2-1) 14+2 = 16/3 = 5
            if(it->second==1)
            {
                return -1;
            }
            ans+=(it->second+2)/3;
            
        }
        return ans;
        
    }
};


