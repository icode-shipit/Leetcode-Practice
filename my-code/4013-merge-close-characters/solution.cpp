class Solution {
public:
    string mergeCharacters(string s, int k) {
        bool found=true;
        while(found)
        {
            found=false;
            for(int i=0;i<s.size();i++)
            {
                int p1=i;
                for(int p2=i+1;p2<s.size() && p2-p1<=k;p2++)
                    {
                        if(s[p2]==s[p1])
                        {
                            s.erase(p2,1);
                            found=true;
                            i=-1;
                            break;
                        }
                    }
            }
        }
        return s;
    }
};
