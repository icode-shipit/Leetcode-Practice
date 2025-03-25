class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int p=0;
        int q=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
             if(nums[i]==nums[j])
             {
                p++;
                q=i;
             }
            }
            if(p>nums.size()/2)
            {
              return nums[q];
            }
            p=0;
        }
        return {};
    }
};
