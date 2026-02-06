class Solution {
public:
    int ans=0;
    void bs(vector<int>& nums,int low,int high)
    {
        while(low<=high)
        {
        int mid=(low+high)/2;
        ans=mid;
        if(mid-1<0)
        {
            if(nums[mid]>nums[mid+1])
            {
                return;
            }
            else
            {
                low=mid+1;
            }
        }
        else if(mid+1>=nums.size())
        {
            if(nums[mid]>nums[mid-1])
            {
                return;
            }
            else
            {
                high=mid-1;
            }
        }
        else if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
        {
            return;
        }
        else if(nums[mid]<nums[mid+1])
        {
            low=mid+1;
        }
        else if(nums[mid]<nums[mid-1])
        {
            high=mid-1;
        }
        }
    }
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
        {
            return 0;
        }
        bs(nums,0,nums.size()-1);
        return ans;
    }
};
