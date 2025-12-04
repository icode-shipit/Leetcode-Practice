class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1)
        {
            if(nums[0]!=target)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
        int s=0;
        int e=nums.size()-1;
        while(s<=e)
        {
           int mid=(s+e)/2;
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
            e=mid-1;
           }
        }
        return -1;
    }
};
