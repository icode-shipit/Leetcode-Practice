    class d_t
    {
       public:
       int eq_time;
       int pr_time;
       int index;  
       d_t(int e,int p,int i)
       {
        eq_time=e;
        pr_time=p;
        index=i;
       }
    };

    class compare
    {
      public:
      bool operator()(const d_t* a, const d_t* b)
      {
        return a->eq_time > b->eq_time;
      }
    };

class Solution {
public:
    // for pq1 first->enqueue_time,processing_time,index
    // for pq2 first->processing_time, second->index

    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        priority_queue< d_t*, vector<d_t*>, compare > pq1;
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq2;

        for(int i=0;i<tasks.size();i++)
        {
            d_t* ptr= new d_t(tasks[i][0],tasks[i][1],i);
            pq1.push(ptr);
        }
        long long time=0;
        while(!pq1.empty() || !pq2.empty())
        {
            if(pq2.empty())
            {
              time = pq1.top()->eq_time; 
            }
            while(!pq1.empty() && time>=pq1.top()->eq_time)
            {
                d_t* ptr= pq1.top();
                pq2.push({ptr->pr_time,ptr->index});
                pq1.pop();
                delete ptr;
            }
            while(!pq2.empty())
            {
                time=time+pq2.top().first;
                ans.push_back(pq2.top().second);

                pq2.pop();
                while(!pq1.empty() && time>=pq1.top()->eq_time)
                {
                d_t* ptr= pq1.top();
                pq2.push({ptr->pr_time,ptr->index});
                pq1.pop();
                delete ptr;
                }
            }
        }
        return ans;

    }
};
