//Leetcode - Longest consecutive sequence - Medium
//https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    //Put all the numbers into a set
        unordered_set<int> seq(nums.begin(),nums.end());
        int longest = 0;
        for(auto &s:seq)
        {
            //Checking if the number is a start of the sequence ie if there is no (n-1) in the set
            //seq.count() returns the number of occurences of the element
            if(!seq.count(s-1))
            {
                int length = 1;
                //Checking if the next continuous elements are there and then incrementing the length
                while(seq.count(s+length))
                {
                    length++;
                }
                longest = max(length,longest);
            }
        }
        return longest;
        
    }
};
