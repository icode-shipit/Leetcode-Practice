class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        unordered_map<int,int> m1; // maps freq of freq of elements
        for(auto it=m.begin();it!=m.end();it++)
        {
            m1[it->second]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(m1[m[nums[i]]]==1)
            {
                return nums[i];
            }
        }
        return -1;
    }
};
