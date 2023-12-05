#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        unordered_map<char,char> parens={
            {'}','{'},
            {')','('},
            {']','['}
        };
        
        for(const auto& c:s)
        {
            if(parens.find(c)!=parens.end(c))
            {
                if(st.empty())
                {
                    return false;
                }
            
            if(st.top()!=parens[c])
            {
                return false;
            }
            st.pop();
            }
            else
            {
                st.push(c);
            }
        }
        return st.empty();
        
    }
};

int main()
{
Solution sol;
char str[]={"()[]{}"};
bool res=sol.isValid(str);
cout<<res<<endl;
}


