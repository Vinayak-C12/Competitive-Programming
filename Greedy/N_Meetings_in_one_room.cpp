//GeeksforGeeks - N Meetings in one room - Easy
//https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> meeting;
        for(int i=0;i<n;i++)
        {
            meeting.push_back({end[i],start[i]});
        }
        sort(meeting.begin(),meeting.end()); // Sort according to the end times and then use greedy method to find the meetings count
        int count =0;
        int e = -1;
        for(int i=0;i<n;i++)
        {
            if(meeting[i].second>e)
            {
                count++;
                e = meeting[i].first;
            }
        }
        return count;
    }
};
