class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
        for(int i=0;i<tasks.size();i++)
        {
            m[tasks[i]]++;
        }
        priority_queue<int> pq;
        for(auto it=m.begin();it!=m.end();it++)
        {
            pq.push(it->second);
        }
        queue<pair<int,int>> q; //first->no of tasks left,second->at what time that tasks can be accessed
        int time=0;
        while(!q.empty() || !pq.empty())
        {
            if(pq.empty())
            {
                while(time<q.front().second)
                {
                    time++;
                }
                pq.push(q.front().first);
                q.pop();
            }
            else
            {
                if(!q.empty() && q.front().second==time)
                {
                    pq.push(q.front().first);
                    q.pop();
                }
                else
                {
                time++;
                if(pq.top()-1!=0)
                {
                   q.push({pq.top()-1,time+n});
                }
                pq.pop();
                }
            }
        }
        return time;
    }
};
