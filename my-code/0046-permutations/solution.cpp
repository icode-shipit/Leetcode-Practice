class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()==0)
        {
            return {{}};
        }
        int nums0=nums[0];
        vector<int> nums_copy(nums.begin()+1,nums.end());
        vector<vector<int>> perm = permute(nums_copy);
        vector<vector<int>> ans;
        for(int i=0;i<perm.size();i++)
        {
            for(int j=0;j<=perm[i].size();j++)
            {
                vector<int> perm_copy=perm[i];
                perm_copy.insert(perm_copy.begin()+j,nums0);
                ans.push_back(perm_copy);
            }
        }
        return ans;
    }
};
