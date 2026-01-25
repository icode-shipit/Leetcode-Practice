class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    void backtracking(vector<int>& nums,int p)
    {
        if(p==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[p]);
        backtracking(nums,p+1);
        temp.pop_back();
        while(p<nums.size()-1 && nums[p]==nums[p+1])
        {
            p++;
        }
        backtracking(nums,p+1);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtracking(nums,0);
        return ans;
    }
};
