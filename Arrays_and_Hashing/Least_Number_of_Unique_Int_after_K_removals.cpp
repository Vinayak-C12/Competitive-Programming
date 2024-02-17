//LeeCode -Least Number of Unique integers left after K removals - Medium
//https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/

// O(NlogN) Solution

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> um;
        vector<int> res;
        for(auto n : arr)
        {
            um[n]++;
        }
        for(auto it: um)
        {
            res.push_back(it.second);
        }
        sort(res.begin(),res.end());
        int m = res.size();
        int i =0;
        for(i=0;i<m;i++)
        {
            if(res[i] <= k)
            {
                k = k - res[i];
            }
            else
            {
                break;
            }
        }
        return m-i;
    }
};

// O(N) Solution but beats less % due to Micro Optimisations

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> map;
        for(auto i: arr){
            map[i]++;
        }
        int uniq = map.size();

        vector<int> freq(100000, 0);
        for(auto i: map){
            freq[i.second]++;
        }
        for(int i=1; i < 100000; i++){
            if(freq[i]==0)
                continue;
            int left = k/i;
            if(left==0) {
                break;
            } else {
                left = min(left, freq[i]);
                uniq -= left;
                k -= left * i;
            }
        }
        return uniq;
    }
};
