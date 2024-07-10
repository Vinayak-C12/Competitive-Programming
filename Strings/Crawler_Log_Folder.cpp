//Leetcode - Crawler Log Folder - Easy
//https://leetcode.com/problems/crawler-log-folder/description/?envType=daily-question&envId=2024-07-10

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();
        int count = 0;
        for(auto str:logs)
        {
            if(str == "./")
            {
                continue;
            }
            else if(str == "../")
            {
                if(count>0)
                {
                    count--;
                }
            }
            else
            {
                count++;
            }
        }
        return count;
    }
};
