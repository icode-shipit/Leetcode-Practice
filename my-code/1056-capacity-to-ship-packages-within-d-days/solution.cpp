class Solution {
public:

    bool feasible(vector<int>& weights,int days,int cap)
    {
        int i=0;
        int reqdays=0;
       while(i<weights.size())
       {
        if(reqdays>=days)
        {
            return false;
        }
        int temp=0; //total weight it can carry in a day
        while(i<weights.size() && temp+weights[i]<=cap)
        {
            temp=temp+weights[i];
            i++;
        }
        reqdays++;
        if(temp==0)
        {
            i++;
        }
       }
       if(reqdays<=days)
       {
        return true;
       }
       return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxcap=accumulate(weights.begin(),weights.end(),0);
        int mincap=*max_element(weights.begin(),weights.end());
        int ans=maxcap;

        while(mincap<=maxcap)
        {
            int mid=(maxcap+mincap)/2;
            if(feasible(weights,days,mid))
            {
                ans=mid;
                maxcap=mid-1;
            }
            else
            {
                mincap=mid+1;
            }
        } 
        return ans;
    }
};
