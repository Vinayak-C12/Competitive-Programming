//Leetcode - Sliding Window Maximum - Hard
//https://leetcode.com/problems/sliding-window-maximum/description/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        deque<int> dq;
        vector<int> res;
        int i = 0;// To indicate the start of the window
        int j = 0;
        while(j<nums.size())
        {
            while(!dq.empty()&&nums[dq.back()]<nums[j])
            {
                dq.pop_back();
            }
            dq.push_back(j);
            if(i>dq.front())
            {
                dq.pop_front();
            }
            if(j+1>=k)
            {
                res.push_back(nums[dq.front()]);
                i++;
            }
            j++;
        }
        return res;
        
    }
};
