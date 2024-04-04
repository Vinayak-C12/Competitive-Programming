//LeetCode - First Non Repeating Character in a string - Easy
//https://leetcode.com/problems/first-unique-character-in-a-string/description/?envType=daily-question&envId=2024-02-05

class Solution {
public:
    int firstUniqChar(string s) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = s.size();
        vector<int> arr(26,0);
        for(int i =0 ;i<n;i++)
        {
            arr[s[i]-'a']++;
        }
        for(int i =0 ;i<n;i++)
        {
            if(arr[s[i]-'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};

