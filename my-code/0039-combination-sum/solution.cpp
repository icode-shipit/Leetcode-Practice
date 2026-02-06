class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void backtracking(vector<int>& candidates, int target,int i,int curr_sum)
    {
        if(curr_sum>target)
        {
            return;
        }
        if(curr_sum==target)
        {
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<candidates.size();j++)
        {
           temp.push_back(candidates[j]);
           backtracking(candidates,target,j,curr_sum+candidates[j]);
           temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates,target,0,0);
        return ans;
    }
};
