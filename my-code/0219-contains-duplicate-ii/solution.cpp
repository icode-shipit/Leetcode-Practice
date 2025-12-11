class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int l=0;
        int r=k;
        for(int i=0;i<nums.size();i++)
        {
            if(i<=k)
            {
                if(!m.contains(nums[i]))
                {
                  m[nums[i]]=1;
                }
                else
                {
                    return true;
                }
            }
            else
            {
              m.erase(nums[l]);
              l++;
              r++;
              if(!m.contains(nums[r]))
              {
                m[nums[r]]=1;
              }
              else
              {
                return true;
              }
            }
        }
        return false;
    }
};
