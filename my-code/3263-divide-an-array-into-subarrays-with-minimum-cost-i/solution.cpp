class Solution {
public:
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int minimumCost(vector<int>& nums) {
        int ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            pq.push({nums[i],i});
        }
        ans+=pq.top().first;
        pq.pop();
        ans+=pq.top().first;
        return ans;
    }
};
