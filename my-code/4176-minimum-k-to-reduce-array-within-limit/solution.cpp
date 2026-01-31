class Solution {
public:
    int nonPositive(vector<int>& nums,int k)
    {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int temp=nums[i];
            int q=temp/k;
            int r=temp%k;
            if(r>0)
            {
                ans+=q+1;
            }
            else
            {
                ans+=q;
            }
        }
        return ans;
    }
    int minimumK(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        long low=sqrt(nums.size());
        long high=1e5;
        int ans=high;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(nonPositive(nums, mid) <= 1LL * mid * mid)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
            low = mid + 1;
            }
        }
        return ans;
    }
};
