class Solution {
public:
    bool backtracking(int i,string& s,long long parparval,long long parval)
    {
        if(i==s.size() && parparval!=-1)
        {
            return true;
        }
        long long leftval = 0;
        for(int j=i;j<s.size();j++)
        {
            if(leftval > LLONG_MAX/10) break;
            leftval = leftval*10 + (s[j]-'0');
            if(parval==-1 || parval-leftval==1) // checking for further possibilities
            {
               if(backtracking(j+1,s,parval,leftval)==true)
               {
                 return true;
               }
            }
            else if(parval!=-1 && leftval>=parval) break;
        }
        return false;
    }
    bool splitString(string s) {
        return backtracking(0,s,-1,-1);
    }
};
