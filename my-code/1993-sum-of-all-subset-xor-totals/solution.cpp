class Solution {
public:
    int ans;
    void backtracking(vector<int>& nums,int p,int curr_xor)
    {
        if(p==nums.size())
        {
            ans=ans+curr_xor;
            return;
        }
        backtracking(nums,p+1,curr_xor ^ nums[p]); // include case
        backtracking(nums,p+1,curr_xor); // not include case
        return;
    }
    int subsetXORSum(vector<int>& nums) {
        backtracking(nums,0,0);
        return ans;
    }
};
