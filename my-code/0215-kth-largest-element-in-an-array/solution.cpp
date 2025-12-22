class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int ans;
        make_heap(nums.begin(),nums.end());
        int i=0;
        while(i<k)
        {
            i++;
            ans=nums.front();
            pop_heap(nums.begin(),nums.end());
            nums.pop_back();
        }
        return ans;
    }
};
