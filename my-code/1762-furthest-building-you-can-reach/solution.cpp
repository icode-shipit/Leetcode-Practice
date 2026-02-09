class Solution {
public:
    // long long total_sum=0;
    // priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>> pq;
    int ans;
    // bool valid(priority_queue<int> pq,int ladders,int bricks)
    // {
    //     long long temp=total_sum;
    //     while(ladders>0 && !pq.empty())
    //     {
    //         temp-=pq.top();
    //         pq.pop();
    //         ladders--;
    //     }
    //     if(temp>bricks)
    //     {
    //         return false;
    //     }
    //     return true;
    // }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        for(int i=0;i<heights.size();i++)
        {
           if(i==heights.size()-1)
           {
              return i;
           }
           ans=i;
           if(heights[i]>=heights[i+1])
           {
              continue;
           }
           else if(heights[i]<heights[i+1])
           {
              if(pq.size()<ladders)
              {
                pq.push(heights[i+1]-heights[i]);
                continue;
              }
            //   else
            //   {
            //     total_sum+=heights[i+1]-heights[i];
            //     pq.push(heights[i+1]-heights[i]);
            //     if(valid(pq,ladders,bricks)==1)
            //     {
            //         continue;
            //     }
            //     else
            //     {
            //         break;
            //     }
               else
               {
                pq.push(heights[i+1]-heights[i]);
                if(bricks-pq.top()>=0)
                {
                    bricks-=pq.top();
                    pq.pop();
                }
                else
                {
                    break;
                }
               } 
            }
           }
           return ans;
    }
};
