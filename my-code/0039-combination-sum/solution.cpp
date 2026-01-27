class Solution {
public:
   vector<int> temp;
   vector<vector<int>> ans;
   void backtracking(vector<int>& candidates, int target,int p,int curr_sum)
   {
        if(curr_sum>target || p==candidates.size())
        {
            return;
        }
        else if(curr_sum==target)
        {
            ans.push_back(temp);
            return;
        }
        else
        {
        temp.push_back(candidates[p]);
        backtracking(candidates,target,p,curr_sum+candidates[p]);
        temp.pop_back();
        backtracking(candidates,target,p+1,curr_sum);
        return;
        }
   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates,target,0,0);
        return ans;
    }
};
