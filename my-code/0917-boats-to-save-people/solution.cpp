class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        if(people.size()==1)
        {
            return 1;
        }
        else
        {
            sort(people.begin(),people.end());
            int p1=0;
            int p2=people.size()-1;
            int ans=0;
            while(p1<=p2)
            {
               if(p1==p2)
               {
                ans++;
                break;
               }
               else if(people[p1]+people[p2]<=limit)
               {
                ans++;
                p1++;
                p2--;
               }
               else
               {
                  ans++;
                  p2--;
               }
            }
            return ans;
        }
    }
};
