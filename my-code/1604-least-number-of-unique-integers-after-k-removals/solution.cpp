class Solution {
public:
    unordered_map<int,int> m;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        for(int i=0;i<arr.size();i++)
        {
           m[arr[i]]++; 
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
            pq.push({it->second,it->first});
        }
            while(pq.top().first>0 && k>0)
            {
                if(k<pq.top().first)
                {
                    return pq.size();
                }
                else if(k==pq.top().first)
                {
                    return pq.size()-1;
                }
                else
                {
                    k=k-pq.top().first;
                    pq.pop();
                }
            }
        return pq.size();
    }
};
