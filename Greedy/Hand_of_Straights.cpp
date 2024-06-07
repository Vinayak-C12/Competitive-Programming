//Leetcode - Hand of Straights - Medium
//https://leetcode.com/problems/hand-of-straights/description/?envType=daily-question&envId=2024-06-06

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0)
        {
            return false;
        }
        sort(hand.begin(),hand.end());
        for(int i=0;i<n;i++)
        {
            if(hand[i]>=0)
            {
                if(!findsuc(hand,groupSize,i,n)) return false;
            }
        }
        return true;
    }
private:
    bool findsuc(vector<int>& hand,int size,int i,int n)
    {
        int next = hand[i]+1;// The next element
        int c=1;// Seq length
        hand[i]=-1;
        i++;
        while(i<n && c<size)// i must be within bounds and c must be less than groupSize
        {
            if(hand[i] == next)
            {
                c++;
                next = hand[i]+1;
                hand[i]=-1;// Mark the number as used 
            }
            i++;
        }
        return c == size;
    }
};

/*

LOGIC:
->Its basically a greedy approach
->From the question its clear that each group must hav consecutive numbers. If it doesnt then return false
->tart from a index and try to see if u can find a consective sequence. If u can return true and mark all the used numbers as -1. If not then return false
->So all the numbers must be present in one of those sequences to return true
->Keep on trying until u finish all numbers

*/
