
class Solution {
public:
    unordered_map<int,int> m;
    vector<vector<int>> ans;
    vector<int> temp;
    void backtracking(vector<int>& nums)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second>0)
            {
                temp.push_back(it->first);
                it->second--;
                backtracking(nums);
                temp.pop_back();
                it->second++;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        backtracking(nums);
        return ans;
    }
};
