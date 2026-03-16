class Solution {
public:
    string ans;
    bool digits[10] = {true, true, true, true, true, true, true, true, true, true};
 // true->available,false->used
    int minavail()
    {
        for(int i=1;i<10;i++)
        {
            if(digits[i]==true)
            {
                return i;
            }
        }
        return -1; // never happens bcz maxlen of input string is 8
    }
    bool backtracking(string& pattern,int p)
    {
        if(p==pattern.size())
        {
            return true;
        }
        if(ans.empty())
        {
           for(int i=minavail();i<10;i++)
           {
            if(digits[i]==false) continue;
              ans.push_back('0' +i);
              digits[i]=false;  
              if(backtracking(pattern,p)==true)
              {
                return true;
              }
              ans.pop_back();
              digits[i]=true;
           }
        }
        // for remaining values it depends on prev val
            for(int i=minavail();i<10;i++)
            {
                if(digits[i]==false) continue;
                if(i<(ans[ans.size()-1]-'0') && pattern[p]=='I')
                {
                    continue;
                }
                else if(i>(ans[ans.size()-1]-'0') && pattern[p]=='D')
                {
                    continue;
                }
                ans.push_back('0' +i);
                digits[i]=false;
                if(backtracking(pattern,p+1)==true)
                {
                   return true;
                }
                ans.pop_back();
                digits[i]=true;
            }
            return false;
    }
    string smallestNumber(string pattern) {
        bool rand=backtracking(pattern,0);
        return ans;
    }
};
