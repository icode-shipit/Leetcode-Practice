class Solution {
public:
    int maxf(unordered_map<char,int> &m)
    {
        int maxcount=0;
        for(auto it=m.begin();it!=m.end();it++)
        {
            maxcount=max(it->second,maxcount);
        }
        return maxcount;
    }
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int ans=0;
        unordered_map<char,int> m;
        while(r<s.size())
        {
            m[s[r]]++;
            int size=r-l+1;
            r++;
            if(size-maxf(m)<=k)
            {
               ans=max(ans,size);
            }
            else
            {
               while(size-maxf(m)>k)
               {
                m[s[l]]--;
                l++;
                size--;
               }
               ans=max(ans,size);
            }
        }
        return ans;
    }
};
