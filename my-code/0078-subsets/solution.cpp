class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void backtracking(vector<int>& nums,int p)
    {
        if(p==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[p]);
        backtracking(nums,p+1); //include case
        temp.pop_back();
        backtracking(nums,p+1); //not include case
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums,0);
        return ans;
    }
};
