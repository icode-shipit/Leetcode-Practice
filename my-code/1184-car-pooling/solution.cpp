class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq1; // first->fromi,seconod->index of trips[i]
        for(int i=0;i<trips.size();i++)
        {
            pq1.push({trips[i][1],i});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq2; // first->toi,second->numpass
        int curr_dist=0;
        int curr_cap=0;
        while(!pq1.empty())
        {
            while(!pq2.empty() && pq2.top().first <= pq1.top().first)
            {
                curr_cap=curr_cap-pq2.top().second;
                pq2.pop();
            }
            if(!pq1.empty() && capacity-(curr_cap)>=trips[pq1.top().second][0])
            {
                curr_cap=curr_cap+trips[pq1.top().second][0];
                pq2.push({trips[pq1.top().second][2],trips[pq1.top().second][0]});
                pq1.pop();
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
