//LeetCode - Queue using Stacks - Easy
//https://leetcode.com/problems/implement-queue-using-stacks/description/?envType=daily-question&envId=2024-01-29

class MyQueue {
private:
    stack<int> stk1;
    stack<int> stk2;   
public:
    MyQueue() {
     
    }
    
    void push(int x) {
        stk1.push(x);        
    }
    
    int pop() {
        int s = 0;
        if(stk2.empty())
        {
            while(!stk1.empty())
            {
                s = stk1.top();
                stk1.pop();
                stk2.push(s);
            }
        }
        s = stk2.top();
        stk2.pop();
        return s;        
    }
    
    int peek() {
        if(stk2.empty())
        {
            while(!stk1.empty())
            {
                int s = stk1.top();
                stk1.pop();
                stk2.push(s);
            }
        }
        return stk2.top();
    }
    
    bool empty() {
        if(stk1.empty() && stk2.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
 
 // Time Complexity - O(N) - Amortized Analysis
