class Solution {
public:
    struct compare{
      bool operator()(const pair<vector<int>,int> &a, const pair<vector<int>,int> &b)
      {
        return a.second<b.second;
      }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue< pair<vector<int>,int>, vector<pair<vector<int>,int>>, compare> maxheap;
        for(int i=0;i<points.size();i++)
        {
           int dist=pow(points[i][0],2)+pow(points[i][1],2);
           if(i<=k-1)
           {
            maxheap.push({points[i],dist});
           }
           else
           {
            if(dist<maxheap.top().second)
            {
                maxheap.pop();
                maxheap.push({points[i],dist});
            }
           }
        }
        while(!maxheap.empty())
        {
          ans.push_back(maxheap.top().first);
          maxheap.pop();
        }
        return ans;
    }
};
