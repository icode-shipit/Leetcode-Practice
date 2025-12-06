class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0;
        int fast=0;
        do
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        } while(slow!=fast);
        int temp=slow;
        int start=0;
        do
        {
            temp=nums[temp];
            start=nums[start];
        } while(start!=temp);
        return start;
    }
};
