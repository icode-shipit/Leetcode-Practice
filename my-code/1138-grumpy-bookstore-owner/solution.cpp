class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int max_wid=0;
        int curr_wid=0;
        int total_sat=0;
        int l=0;
        for(int i=0;i<customers.size();i++)
        {
            if(grumpy[i]==1)
            {
              curr_wid+=customers[i]; 
            }
            else if(grumpy[i]==0)
            {
               total_sat+=customers[i];
            }
            if(i-l+1>minutes)
            {
                if(grumpy[l]==1)
                {
                    curr_wid-=customers[l];
                }
                l++;
            }
            max_wid=max(max_wid,curr_wid);
        }
        return total_sat+max_wid;
    }
};
