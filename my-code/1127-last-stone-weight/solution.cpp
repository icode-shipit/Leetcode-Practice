class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq1;
        for(int i=0;i<stones.size();i++)
        {
           pq1.push(stones[i]);
        }
        while(pq1.size()>1)
        {
            int w1=pq1.top();
            pq1.pop();
            int w2=pq1.top();
            pq1.pop();
            if(w1>w2)
            {
                pq1.push(w1-w2);
            }
            else if(w1<w2)
            {
                pq1.push(w2-w1);
            }
        }
        if(pq1.empty())
        {
            return 0;
        }
        else
        {
            return pq1.top();
        }
    }
};
