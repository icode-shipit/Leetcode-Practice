class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    set<vector<int>> s;
    void backtracking(vector<int>& nums,int p)
    {
        if(p==nums.size())
        {
            if(!s.contains(temp) && temp.size()>1)
            {
               ans.push_back(temp);
               s.insert(temp);
            }
           return;
        }
        if(temp.empty() || temp[temp.size()-1]<=nums[p])
        {
        temp.push_back(nums[p]);
        backtracking(nums,p+1);
        temp.pop_back();
        }
        backtracking(nums,p+1);
        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums,0);
        return ans;
    }
};
