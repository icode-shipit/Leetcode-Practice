class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0;
        int l=nums.size()-1;
        int mid;
        while(s<=l)
        {
           mid=s+(l-s)/2;

        if(nums[mid]==target)
        {
            return mid;
        }

        else if(nums[mid]<target)
         {
            s=mid+1;
         }

         else
         {
            l=mid-1;
         }

        }
        int i=0;
        if(nums[0]>target)
        {
            return 0;
        }
        else if(nums[nums.size()-1]<target)
        {
            return nums.size();
        }
        while(nums[i]<target)
        {
            if(nums[i+1]>target)
            {
                return i+1;
            }
           i++;
        }
        return {};
    }
};
