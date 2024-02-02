//LeetCode - Sequential Digits - Medium
//https://leetcode.com/problems/sequential-digits/description/?envType=daily-question&envId=2024-02-02

//APPROACH - 1: Substring Method
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        string c = "123456789";
        vector<int>a;

        for(int i =0;i<c.size();i++){
            for(int j =i+1;j<=c.size();j++){
                int curr = stoi(c.substr(i,j-i));
                if(curr<=high && curr>=low)a.push_back(curr);
            }
        }
        sort(a.begin(),a.end());
        return a;
    }
};

//APPROACH -2 : 
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> res, ref;
        ref = {12, 23, 34, 45, 56, 67, 78, 89, 123, 234, 345, 456, 567, 678, 789, 1234, 2345, 
        3456, 4567, 5678, 6789, 12345, 23456, 34567, 45678, 56789, 123456, 234567, 345678, 456789, 
        1234567, 2345678, 3456789, 12345678, 23456789, 123456789};
        for(int i = 0; i<ref.size();i++)
        {
            if(ref[i]>=low && ref[i]<=high)
            {
                res.push_back(ref[i]);
            }
        }
        return res;
    }
};

//APPROACH - 3:
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> a;

        for (int i = 1; i <= 9; ++i) {
            int num = i;
            int nextDigit = i + 1;

            while (num <= high && nextDigit <= 9) {
                num = num * 10 + nextDigit;
                if (low <= num && num <= high) a.push_back(num);
                ++nextDigit;
            }
        }

        sort(a.begin(), a.end());
        return a;
    }
};






