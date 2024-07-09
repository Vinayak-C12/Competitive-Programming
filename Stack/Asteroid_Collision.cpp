//Leetcode - Asteroid Collision - Medium
//https://leetcode.com/problems/asteroid-collision/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> stk;
        for(int i=0;i<n;i++)
        {
            if(stk.empty() || asteroids[i]>0)
            {
                stk.push(asteroids[i]);
            }
            else if(asteroids[i]<0)
            {
                while(!stk.empty() && stk.top()>0 && (abs(asteroids[i])>stk.top()))
                {
                    stk.pop();
                }
                if(!stk.empty() && stk.top()>0)
                {
                    if(stk.top() == abs(asteroids[i]))
                    {
                        stk.pop();
                    }
                }
                else
                {
                    stk.push(asteroids[i]);
                }
            }
        }
        vector<int>ans;
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
