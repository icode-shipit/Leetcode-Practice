class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        pair<int,int> ans={INT_MAX,-1};
        for(int i=0;i<capacity.size();i++)
            {
                if(capacity[i]>=itemSize)
                {
                    if(ans.first>capacity[i])
                    {
                        ans={capacity[i],i};
                    }
                }
            }
        return ans.second;
    }
};
