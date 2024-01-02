//Leetcode - Car Fleet - Medium
//https://leetcode.com/problems/car-fleet/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,double>> cars;
        for(int i =0;i<n;i++)
        {
            double time = (double)(target-position[i])/speed[i];
            cars.push_back({position[i],time});
        }
        sort(cars.begin(),cars.end());
        double maxtime = 0.0;
        int result = 0;
        for(int i = n-1;i>=0;i--)
        {
            double time = cars[i].second;
            if(time>maxtime)
            {
                result++;
                maxtime = time;
            }
        }
        return result;
        
    }
};
