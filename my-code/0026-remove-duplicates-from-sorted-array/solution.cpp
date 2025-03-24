class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p=1;
        int tempp=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(tempp!=nums[i])
            {
                nums[p]=nums[i];
                tempp=nums[i];
                p++;
            }
        }
        return p;
    }
};
