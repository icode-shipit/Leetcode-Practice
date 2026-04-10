class Solution {
public:
    vector<int> needs1;
    int budget=0;
    int ans=INT_MAX;
    bool checker(vector<int>& offer) // if the offer is usable, it also has changing needs functionality
    {
        for(int i=0;i<offer.size()-1;i++)
        {
            if(offer[i]>needs1[i])
            {
                return false;
            }
        }
        for(int i=0;i<offer.size()-1;i++)
        {
            needs1[i]-=offer[i];
        }
        budget+=offer[offer.size()-1];
        return true;
    }
    void backtracking(vector<int>& price, vector<vector<int>>& special,vector<bool>& invalid_off)
    {
        if(budget>=ans)
        {
            return;
        }
        if(accumulate(needs1.begin(),needs1.end(),0)==0)
        {
           ans=min(ans,budget);
           return;
        }
        for(int i=0;i<special.size();i++)
        {
            if(!invalid_off[i] && checker(special[i])==true)
            {
                backtracking(price,special,invalid_off);
                for(int j=0;j<special[i].size()-1;j++) // reverting changes back
                {
                    needs1[j]+=special[i][j];
                }
                budget-=special[i][special[i].size()-1];
            }
        }
        if(accumulate(needs1.begin(),needs1.end(),0)!=0)// means u cant use any offer so use stand prices 
        {
            int prev_budget=budget;
            for(int i=0;i<needs1.size();i++)
            {
                budget+=needs1[i]*price[i];
            }
            ans=min(ans,budget);
            budget=prev_budget;
        }
        return;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        needs1=needs;
        vector<bool> invalid_off(special.size(),false);
        for(int i=0;i<special.size();i++)
        {
            int std_budget=0;
            int off_budget=special[i][special[i].size()-1];
            for(int j=0;j<special[i].size()-1;j++) //checking if special[i] is invalid/not
            {
                std_budget+=special[i][j]*price[j];
            }
            if(std_budget<off_budget)
            {
                invalid_off[i]=true;
            }
        }
        backtracking(price,special,invalid_off);
        return ans;
    }
};
