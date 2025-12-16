class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1 || prices.size()==0)
        {
            return 0;
        }
        int l=0;
        int r=0;
        int maxprofit=0;
        while(r<prices.size()-1)
        {
           if(prices[r+1]>=prices[r])
           {
            r++;
            maxprofit=max(maxprofit,prices[r]-prices[l]);
           }
           else
           {
            while(r<prices.size()-1 && prices[r]<prices[l])
            {
                if(r<prices.size()-1)
                {
                l=r;
                r=l+1;
                maxprofit=max(maxprofit,prices[r]-prices[l]);
                }
            }
            if(r>=prices.size()-1)
            {
            return maxprofit;
            }
            r++;
            while(r<prices.size()-1 && prices[r]<prices[l])
            {
                l=r;
                r=l+1;
                maxprofit=max(maxprofit,prices[r]-prices[l]);
            }
            maxprofit=max(maxprofit,prices[r]-prices[l]);
           }
        }
        return maxprofit;
    }
};
