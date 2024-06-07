//Leetcode - Find Common Characters - Easy(Not ez tbh)
//https://leetcode.com/problems/find-common-characters/description/?envType=daily-question&envId=2024-06-05

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        vector<int> count(26,0);
        vector<string> res;
        for(auto c:words[0])
        {
            count[c-'a']++;
        }
        for(int i=1;i<n;i++)
        {
            vector<int> counts(26,0);
            for(auto c:words[i])
            {
                counts[c-'a']++;
            }
            for(int i=0;i<26;i++)
            {
                count[i] = min(count[i],counts[i]);
            }
        }
        for(int i=0;i<26;i++)
        {
            if(count[i]>0)
            {
                while(count[i]>0)
                {
                    res.push_back(string(1,'a'+i));// Basically it creates a string of length 1 and the second argument is the character. Here it get the ascii value of that character using 'a'+i since res is a vector of strings
                    count[i]--;
                }
            }
        }
        return res;
    }
};
