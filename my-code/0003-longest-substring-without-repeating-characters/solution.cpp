class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
        {
            return 0;
        }
        unordered_map<int,int> m;
        int currlen=0;
        int maxlen=1;
        int p1=0;
        int p2=0;
        while(p2<s.size())
        {
            if(!m.contains(s[p2]))
            {
            m[s[p2]]=1;
            p2++;
            currlen=p2-p1;
            maxlen=max(maxlen,currlen);
            }
            else
            {
              while(m.contains(s[p2]))
              {
                m.erase(s[p1]);
                p1++;
              }
              m[s[p2]]=1;
              p2++;
              maxlen=max(maxlen,currlen);
            }
        }
        return maxlen;
    }
};
