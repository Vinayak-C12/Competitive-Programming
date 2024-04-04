//Leetcode - Redistribute Characters to Make All Strings Equal - Easy
//https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        //Hashmap or array can be used
        int map[26]={0};
        int n = words.size();
        if(n==1)
        {
            return true;
        }
        int sum=0;
        for(auto &str:words)
        {
            sum+=str.size();
        }
        //Total chars/Total strings = whole no
        if(sum%n!=0)
        {
            return false;
        }
        //Each occuring char count
        for(auto &str:words)
        {
            for(int i=0;i<str.size();i++)
            {
                map[str[i]-'a']++;
            }
        }
        
        for(int i=0;i<26;i++)
        {
            if(map[i]%n!=0)
            {
                return false;
            }
        }
        return true;
        
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
