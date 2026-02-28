class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        vector<int> ans={-1,-1};
        map<int,int> m1; // freq of each nums element
        for(int i=0;i<nums.size();i++)
            {
                m1[nums[i]]++;
            }
        for(auto it=m1.begin();next(it)!=m1.end();it++)
            {
                for(auto it1=next(it);it1!=m1.end();it1++)
                    {
                        if(it->second!=it1->second)
                        {
                            ans.clear();
                            ans.insert(ans.end(),{it->first,it1->first});
                            return ans;
                        }
                    }
            }
        return ans;
    }
};
