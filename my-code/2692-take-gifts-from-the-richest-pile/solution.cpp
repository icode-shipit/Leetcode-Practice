class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int i=0;i<gifts.size();i++)
        {
            pq.push(gifts[i]);
        }
        while(k>0 && !pq.empty())
        {
            int top=pq.top();
            pq.pop();
            top=floor(sqrt(top));
            if(top>0)
            {
              pq.push(top);
            }
            k--;
        }
        long long ans=0;
        while(!pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};
