class Solution {
public:
    int count=0;
    int maxOR=INT_MIN;
    int temp=0;
    void backtracking(int p,vector<int>& nums)
    {
        if(p==nums.size())
        {
           if(temp>maxOR)
           {
             count=1;
             maxOR=temp;
             return;
           } 
           else if(temp==maxOR)
           {
            count++;
            return;
           }
           return;
        }
        int prevtemp=temp;
        temp=temp | nums[p];
        backtracking(p+1,nums);
        temp=prevtemp;
        backtracking(p+1,nums);
        return;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        backtracking(0,nums);
        return count;
    }
};
