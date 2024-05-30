//Leetcode - Maximum Product Subarray - Medium - Striver
//https://leetcode.com/problems/maximum-product-subarray/description/

//Solution - 1 : Prefix and Suffix

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN;
        int pre = 1,suf = 1;
        for(int i=0;i<n;i++)
        {
            if(pre == 0) {pre=1;}
            if(suf == 0) {suf=1;}
            pre *= nums[i];
            suf *= nums[n-1-i];
            res = max(res, max(pre,suf));
        }
        return res;
    }
};

/*
LOGIC:
-> If all the numbers are positive the max product will be the product of all elements and the same when even no of neg nos ae present
->When odd no of negs r present we need to find the subarray either to right or left of those each neg noes to find the max prod
-> Another edge case will be the presence of 0 and only the max prod can be found in either the left or the right subbarray
->In this approach we try to compute the prefix and the suffix product and get the max among them
*/ 

// Solution - 2:

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prod = 1;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++)
        {
            prod *= nums[i];
            maxi = max(maxi,prod);
            if(prod == 0)
            {
                prod =1;
            }
        }
        prod = 1;
        for(int i = n-1;i>=0;i--)
        {
            prod *= nums[i];
            maxi = max(maxi,prod);
            if(prod == 0)
            {
                prod = 1;
            }
        }
        return maxi;
    }
};

/*
-> Kind of kadane algo modification but we calculate it from both the ends to take into account all the laft and right subaaray
*/
