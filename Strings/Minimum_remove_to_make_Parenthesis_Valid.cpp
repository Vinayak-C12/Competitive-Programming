//Leetcode - Minimum remove to make parenthesis valid - Medium
//https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/?envType=daily-question&envId=2024-04-06

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        int count = 0;
        string res ="";
        vector<char> arr(s.begin(), s.end()); // Covert string to array of char to avoid MLE
        for(int i =0;i<n;i++)
        {
            if(arr[i] == '(')
            {
                count++;
            }
            else if(arr[i] == ')')
            {
                if(count>0)
                {
                    count--;
                }
                else
                {
                    arr[i] = '*';
                }
            }
        }
        for(int i = n-1;i>=0;i--)
        {
            if(arr[i] == '(' && count>0)
            {
                arr[i] = '*';
                count--;
            }
        }
        for(auto c : arr)
        {
            if(c != '*')
            {
                res += c;
            }
        }
        return res;
    }
};


