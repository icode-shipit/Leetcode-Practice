class Solution {
public:

    bool satisfy(int h,vector<int> &piles,long long eatspeed)
    {
       long long reqhrs=0;
       for(int i=0;i<piles.size();i++)
       {
        if(reqhrs>h)
        {
            break;
        }
        reqhrs += (piles[i] + eatspeed - 1) / eatspeed;
       }
       if(reqhrs<=h)
       {
        return true;
       }
       return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int minspeed=1;
        int maxspeed=*max_element(piles.begin(),piles.end());
        if(h==piles.size())
        {
            return maxspeed;
        }
        // The ans lies in bw these above values
        // Lets apply BS algo to find this
        // If mid val can satisfy in those hours then we search the first half and we keep doing this unil mid doesnt satisfy those conditions then we move start ptr to mid+1 thereby we can find our value
        int ans;
        while(minspeed<=maxspeed)
        {
          long long midval=minspeed+(maxspeed-minspeed)/2;
          bool cond=satisfy(h,piles,midval);
          if(cond==true)
          {
            ans=(int)midval;
            maxspeed=(int)midval-1;
          }
          else
          {
            minspeed=(int)midval+1;
          }
        }
        return ans;
    }
};
