class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int size=0;
        string ans("");
        priority_queue<pair<int,char>> pq;
        if(a>0)
        {
            pq.push({a,'a'});
        }
        if(b>0)
        {
            pq.push({b,'b'});
        }
        if(c>0)
        {
            pq.push({c,'c'});
        }
        while(!pq.empty())
        {
            pair<int,char> temp=pq.top();
           if(size>1 && ans[size-1]==ans[size-2] && ans[size-1]==temp.second)
           {
               pq.pop();
               if(pq.empty())
               {
                return ans;
               }
               else
               {
                ans.push_back(pq.top().second);
                size++;

                // pq.top().first--;
                pair<int,char> temp1=pq.top();
                pq.pop();
                if(temp1.first-1>0)
                {
                   pq.push({temp1.first-1,temp1.second}); //changing the val at front
                }
                pq.push(temp);
               }
           }
           else
           {
                ans.push_back(temp.second);
                size++;
                // pq.top().first--;
                pq.pop();
                if(temp.first-1>0)
                {
                   pq.push({temp.first-1,temp.second});
                }
                if(temp.first==0)
                {
                    pq.pop();
                }
            }
        }
        return ans;
    }
};
