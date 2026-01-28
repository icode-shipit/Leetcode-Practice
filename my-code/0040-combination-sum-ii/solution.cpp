class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void backtracking(vector<int>& candidates,int target,int curr_sum,int p)
    {
        if(curr_sum==target)
        {
            ans.push_back(temp);
            return;
        }
        else if(curr_sum>target || p==candidates.size())
        {
            return;
        }
        else
        {
            temp.push_back(candidates[p]);
            backtracking(candidates,target,curr_sum+candidates[p],p+1);
            temp.pop_back();
            while(p<candidates.size()-1 && candidates[p]==candidates[p+1])
            {
                p++;
            }
            backtracking(candidates,target,curr_sum,p+1);
            return;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target,0,0);
        return ans;
    }
};
