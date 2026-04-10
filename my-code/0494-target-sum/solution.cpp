class Solution {
public:
    vector<char> exp;
    int ans=0;
    void backtracking(vector<int>& nums, int target, int curr_sum,int p)
    {
        if(p==nums.size())
        {
            if(curr_sum==target)
            {
                ans++;
            }
            return;
        }
        for(int i=0;i<exp.size();i++)
        {
           if(exp[i]=='+')
           {
            backtracking(nums,target,curr_sum+nums[p],p+1);
           } 
           else if(exp[i]=='-')
           {
            backtracking(nums,target,curr_sum-nums[p],p+1);
           }
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
         exp.push_back('+');
         exp.push_back('-');
         backtracking(nums,target,0,0);
         return ans;
    }
};
