class Solution {
public:
    unordered_map<int,int> m;
    int ans=0;
    void backtracking(vector<int>& nums, int k,int p,int n)
    {
        if(p==n)
        {
            return;
        }
        if(m[nums[p]-k]>0 || m[nums[p]+k]>0)
        {
            ans+=pow(2,n-p-1);
            backtracking(nums,k,p+1,n);
            return;
        }
        m[nums[p]]++;
        backtracking(nums,k,p+1,n);
        m[nums[p]]--;
        backtracking(nums,k,p+1,n);
        return;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        backtracking(nums,k,0,nums.size());
        return pow(2,nums.size())-ans-1;
    }
};
