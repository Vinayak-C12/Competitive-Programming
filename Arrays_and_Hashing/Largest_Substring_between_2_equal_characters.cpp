//Leetcode - Largest Substring between two equal characters
//https://leetcode.com/problems/largest-substring-between-two-equal-characters/

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
    //APPROACH - 1 - Best Solution
        unordered_map<char,int> um;
        int maxdiff = 0;
        for(int i=0;i<n;i++)
        {
            if(um.find(s[i])==um.end())
            {
                um[s[i]]=i;
            }
            else
            {
                int diff = i - um[s[i]];
                maxdiff = max(maxdiff,diff);
            }
        }
        return maxdiff-1;
    
    //APPROACH -2 Uisng Vector for storing indices
        int n = s.size();
        //Map for maintaining the indices of each character
        unordered_map<char,vector<int>> um;
        for(int i=0;i<n;i++)
        {
            um[s[i]].push_back(i);
        }
        //It is initialised to -1 to identify if there were no repeated characters at all(return -1 case)
        int longest =-1;
        for(auto it=um.begin();it!=um.end();it++)
        {
            if(it->second.size()>1)
            {
                //The length will be difference between the largest index seen - the smallest index seen -1
                int length = it->second[it->second.size()-1]-it->second[0]-1;
                //The case of "aa" or "bb"(return 0 case)
                if(length==-1)
                {
                    length = 0;
                }
                longest = max(length,longest);
            }
        }
        return longest;
            
        
    }
};

 //APPROACH - 3 Using pair<int,int> instead of a vector and only storing the highest and lowest index
        unordered_map<char,pair<int,int>> um;
        for(int i=0;i<n;i++)
        {
            if(um.find(s[i])==um.end())
            {
                um[s[i]].first=i;
                um[s[i]].second=i;
            }
            else
            {
                um[s[i]].second=i;
            }
        }
        int longest =-1;
        for(auto it=um.begin();it!=um.end();it++)
        {
            if(it->second.first!=it->second.second)
            {
                
                int length = it->second.second - it->second.first -1;
                longest = max(length,longest);
            }
        }
        return longest;
        

