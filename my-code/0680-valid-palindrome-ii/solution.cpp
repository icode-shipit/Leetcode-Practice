class Solution {
public:
    bool validPalindrome(string s) {
        int l=0;
        int r=s.size()-1;
        while(l<r)
        {
            if(s[l]==s[r])
            {
                l++;
                r--;
            }
            else if(s[l]!= s[r])
            {
                bool ans=true;
                if(s[l+1]!=s[r])
                {
                    ans=false;
                }
                if(s[l+1]==s[r])
                {
                    int nl=l+1;
                    int nr=r;
                    while(nl<nr)
                    {
                        if(s[nl]==s[nr])
                        {
                            nl++;
                            nr--;
                        }
                        else
                        {
                            ans=false;
                            break;
                        }
                    }
                }
                if(ans==true)
                {
                    return true;
                }
                if(s[r-1]==s[l])
                {
                    int nr=r-1;
                    int nl=l;
                    while(nl<nr)
                    {
                        if(s[nl]==s[nr])
                        {
                            nl++;
                            nr--;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
