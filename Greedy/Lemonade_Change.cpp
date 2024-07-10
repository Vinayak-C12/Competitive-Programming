//Leetcode - Lemonade Change - Easy
//https://leetcode.com/problems/lemonade-change/description/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five = 0;
        int ten = 0;
        for(int i=0;i<n;i++)
        {
            if(bills[i] == 5) // Accept directly
            {
                five++;
            }
            else if(bills[i] == 10) // Need to have minimum 1 5 note to provide change
            {
                if(five>0)
                {
                    five--;
                    ten++;
                }
                else
                {
                    return false;
                }
            }
            else // It means it is 20. Need to return 15 which is by either 10+5 or 3*5. Check for its availablity
            {
                if(five>0 && ten>0)
                {
                    five--;
                    ten--;
                }
                else if(five>=3)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
