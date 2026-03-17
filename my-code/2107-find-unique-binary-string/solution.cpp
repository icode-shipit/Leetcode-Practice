class Solution {
public:
    string temp;
    string ans;
    unordered_set<string> s;
    bool backtracking(int p,int n)
    {
        if(p==n)
        {
           if(!s.contains(temp))
           {
            ans=temp;
            return true;
           } 
           return false;
        } 
        for(int i=0;i<2;i++)
        {
            temp.push_back(i+'0');
            if(backtracking(p+1,n)==true)
            {
                return true;
            }
            temp.pop_back();
        } 
        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        bool rand=backtracking(0,nums.size());
        return temp;
    }
};
