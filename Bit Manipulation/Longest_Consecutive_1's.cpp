//GeeksForGeeks - Longest Consecutive 1's - Easy
//https://www.geeksforgeeks.org/problems/longest-consecutive-1s-1587115620/1

class Solution
{
    public:
    int maxConsecutiveOnes(int N)
    {
        // code here
        int len = 0;
        int longest = 0;
        while(N > 0)
        {
            if((N & 1) == 1)
            {
                len++;
            }
            else
            {
                longest = max(len, longest);
                len = 0;
            }
            N >>= 1;
        }
        longest = max(len, longest); // Dont forget this update as it doesnt update when the MSB is not 0
        return longest;
    }
};
