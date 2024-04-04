//LeetCode - Find the Town Judge - Easy
//https://leetcode.com/problems/find-the-town-judge/description/?envType=daily-question&envId=2024-02-22

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> res(n+1,0);
        for(auto num:trust)
        {
            res[num[0]]--;// If a person trusts somebody he cant be the judge. So decrement
            res[num[1]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(res[i] == n-1)// Everyone needs to trust him and he shouldnt trust anone. If he trusts then res[i] will not be equal to N-1
            {
                return i;
            }
        }
        return -1;
    }
};
