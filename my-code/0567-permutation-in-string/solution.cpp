class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
        {
            return false;
        }
        int l=0;
        int r=s1.size()-1;
        vector<int> v1(26,0); // for s1
        vector<int> v2(26,0); // for s2
        for(int i=0;i<s1.size();i++)
        {
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        int matches=0;
        for(int i=0;i<26;i++)
        {
            if(v2[i]==v1[i])
            {
                matches++;
            }
        }
        if(matches==26)
        {
            return true;
        }
    while(r+1<s2.size())
    {
            if(v2[s2[l]-'a']==v1[s2[l]-'a'])
            {
                matches--;
            }
            v2[s2[l]-'a']--;
            if(v2[s2[l]-'a']==v1[s2[l]-'a'])
            {
                matches++;
            }
            l++;
            r++;
            if(v2[s2[r]-'a']==v1[s2[r]-'a'])
            {
                matches--;
            }
            v2[s2[r]-'a']++;
            if(v2[s2[r]-'a']==v1[s2[r]-'a'])
            {
                matches++;
            }
        if(matches==26)
        {
        return true;
        }
    }
        return false;
    }
};
