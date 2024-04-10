//Leetcode - Number of Students unable to eat lunch - Easy
//https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/?envType=daily-question&envId=2024-04-08

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int count = 0;
        int ones = 0;
        int zeroes = 0;
        for(int i=0;i<n;i++)
        {
            if(students[i] == 0)
            {
                zeroes++;
            }
            else
            {
                ones++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(sandwiches[i] == 0)
            {
                if(zeroes > 0)
                {
                    count++;
                    zeroes--;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if(ones > 0)
                {
                    ones--;
                    count++;
                }
                else
                {
                    break;
                }
            }
        }
        return n - count;
    }
};
