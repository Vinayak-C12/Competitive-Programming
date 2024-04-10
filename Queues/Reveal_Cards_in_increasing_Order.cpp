//Leetcode - Reveal Cards in increasing Order - Medium
//https://leetcode.com/problems/reveal-cards-in-increasing-order/description/?envType=daily-question&envId=2024-04-10

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
       int n = deck.size();
       deque<int> q;
       vector<int> res(n,0);
       sort(deck.begin(),deck.end());
       for(int i=0;i<n;i++)
       {
            q.push_back(i);//Initialise the queue with the indices
       }
       for(int i=0;i<n;i++)// Iterate through the numbers and perform the same operation as asked and assign the respective indices to the numbers
       {
            int j = q.front();
            q.pop_front();
            res[j] = deck[i];
            if(!q.empty())
            {
                int k = q.front();
                q.pop_front();
                q.push_back(k);
            }
       } 
       return res;
    }
};
