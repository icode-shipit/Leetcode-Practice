class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int p1=0;
        while(k>0)
        {
            if(p1-1>=0)
            {
              p1--;
              k--;
            }
            else
            {
                p1=nums.size()-1;
                k--;
            }
        }
        unordered_map<int,int> m;
        int i=0;
        int p2=p1+1;
        m[i]=nums[p1];
        i++;
        if(p2>=nums.size())
        {
            p2=0;
        }
        while(p1!=p2)
        {
            m[i]=nums[p2];
            i++;
            if(p2+1>=nums.size())
            {
            p2=0;
            }
            else 
            {
                p2++;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
           nums[i]=m[i];
        }
        m.clear();
        return;
    }
};
