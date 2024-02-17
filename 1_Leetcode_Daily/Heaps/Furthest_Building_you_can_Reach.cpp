//LeetCode - Furthest Building you can Reach - Medium
//https://leetcode.com/problems/furthest-building-you-can-reach/?envType=daily-question&envId=2024-02-17

static const int fast_io = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> pq; // Pq to maintain the jumps using bricks so that we can retrieve the max cost when replacing using bricks with ladders
        for(int i=0;i<n-1;i++)
        {
            int diff = heights[i+1] - heights[i];            
            if(diff <= 0)
            {
                continue;
            }
            bricks -= diff;
            pq.push(diff); // Push all the cost of jumps made using bricks
            if(bricks<0) // This means bricks are not enough so we check if we hav ladders to make the jump
            {
                if(ladders == 0) // If we dont have both bricks and ladders then we cant proceed further
                {
                    return i;
                }
                ladders--;// Use the ladder to make the jump and retrieve the bricks from the jump where max bricks were used by using ladder in that place
                bricks += pq.top();// Get the max value using max heap
                pq.pop();
            }
        }
        return n-1;// If loop doesnt break means we hav reached the last building
    }
};
