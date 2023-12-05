#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map;
	int size = s.length();
	if(size != t.length()){
	  return false;
	}
        for(int i = 0;i<s.size();i++)
        {
            map[s[i]]++;
	    map[t[i]]--;
        }
        for(auto it = map.begin();it!=map.end();it++)
        {
            if(it->second!=0)
            return false;
        }
        return true;
    }
};

int main(){
  Solution sol; 
  auto res = sol.isAnagram("ab", "ba");
  cout << res << endl;  
}
