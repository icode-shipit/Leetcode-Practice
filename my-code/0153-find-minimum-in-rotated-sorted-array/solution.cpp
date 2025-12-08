class Solution {
public:
    int findMin(vector<int>& nums) {
        int minl=0;
        int max=nums.size()-1;
        int ans=nums[0];
        while(minl<=max)
        {
          if(nums[minl]<nums[max])
          {
            ans=min(ans,nums[minl]);
            break;
          }
          int mid=(minl+max)/2;
          ans=min(ans,nums[mid]);
          if(nums[mid]>=nums[minl])
          {
            minl=mid+1;
          }
          else if(nums[mid]<nums[minl])
          {
            max=mid-1;
          }
        }
        return ans;
    }
};
