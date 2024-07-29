//Leetocde - Robot Collisions - Medium
//https://leetcode.com/problems/robot-collisions/description/?envType=daily-question&envId=2024-07-13

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        unordered_map<int,int> um;
        vector<int> res;
        stack<int> stk;
        int n = positions.size();
        for(int i=0;i<n;i++)
        {
            um[positions[i]] = i;
        }
        sort(positions.begin(),positions.end());
        for(int i=0;i<n;i++)
        {
            if(directions[um[positions[i]]] == 'R')
            {
                stk.push(um[positions[i]]);
            }
            else 
            {
                while(!stk.empty() && healths[um[positions[i]]]>0)
                {
                    if(healths[stk.top()]>healths[um[positions[i]]])
                    {
                        healths[stk.top()] = healths[stk.top()] - 1;
                        healths[um[positions[i]]] = 0;
                        break;
                    }
                    else if(healths[stk.top()]<healths[um[positions[i]]])
                    {
                        healths[stk.top()] = 0;
                        healths[um[positions[i]]] -= 1;
                        stk.pop();                        
                    }
                    else
                    {
                        healths[stk.top()] = 0;
                        healths[um[positions[i]]] = 0;
                        stk.pop();
                        break;                        
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(healths[i]>0)
            {
                res.push_back(healths[i]);
            }
        }
        return res;
    }
};

/*
Logic:
-> Collisions happen only when u have some robots moving to the right and then some moving to left
-> Use a stack to accomplish this task
-> Maintain a hashmap for the positions and indices and then sort positions
-> Iterate through positions and push the index onto the stack if the robot is moving right
-> If the robot is moving left then check if there r any robots moving right and then perform the operations
-> Note that a robot that is left moving is never pushed onto the stack coz the 2 cases that can happen is the robot will get eliminated or the left robot destroys all the robots in the stack. But we dont push it into the stack as it is of use once it destroys all robots and moves to the left since it cant collide with anything else after that
*/
