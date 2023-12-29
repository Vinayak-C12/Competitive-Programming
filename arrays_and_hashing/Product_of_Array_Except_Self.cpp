//Leetcode - Medium - Product of Array Except Self
//https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
        vector<int> res(n,1);
        int prefix_prod=1;
        for(int i=0;i<n;i++)
        {
            res[i]*=prefix_prod;
            prefix_prod*=nums[i];
        }
        int suffix_prod=1;
        for(int i=n-1;i>=0;i--)
        {
            res[i]*=suffix_prod;
            suffix_prod*=nums[i];
        }
        return res;
        */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        vector<int> ans(n);
        vector<int> left_Product(n);
        vector<int> right_Product(n);
        left_Product[0] = 1;
        for(int i=1; i<n; i++){
            left_Product[i] = left_Product[i-1] * nums[i-1];
        }
        right_Product[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            right_Product[i] = right_Product[i+1] * nums[i+1];
        }
        for(int i=0; i<n; i++){
            ans[i] = left_Product[i] * right_Product[i];
        }
        return ans;
        
        
    }
};
