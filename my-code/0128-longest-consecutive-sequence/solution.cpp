class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        unordered_set<int> s;
        int maxlen=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        while(!s.empty())
        {
            for(auto it=s.begin();it!=s.end();it++)
            {
                if(!s.contains(*it-1))
                {
                    int p=*it;
                    int len=1;
                    s.erase(p);
                    while(s.contains(p+1))
                    {
                        len++;
                        s.erase(p+1);
                        p++;
                    }
                    maxlen=max(maxlen,len);
                    break;
                }
            }
        }
        return maxlen;
    }
};
