class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        if(nums.size()==1)
        {
            return -1;
        }
        long long total_sum=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            total_sum+=nums[i];
        }
        int ans=INT_MAX;
        long long right_product=1;
        long long right_sum=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            right_sum+=nums[i];
            long long left_sum=total_sum-right_sum;
            if(right_product>left_sum)
            {
                break;
            }
            else if(right_product==left_sum)
            {
                ans=min(ans,i);
            }
            if(right_product > LLONG_MAX/nums[i])
            {
                break;
            }
            right_product*=nums[i];
        }
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};
