class Solution {
public:
    vector<string> ans;
    bool valid(string& s)
    {
        if(s.find('.')==string::npos) // no decimal
        {
           if(s.size()>1 && s[0]=='0') return false;
           return true;
        }
        int pos= s.find('.');
        string left = s.substr(0, pos);
        string right = s.substr(pos + 1);
        if(left.size() > 1 && left[0] == '0') return false;
        if(right.back() == '0') return false;
        return true;
    }
    void helper(string& leftstr,string& rightstr)
    {
        int leftlen= leftstr.size();
        int rightlen= rightstr.size();
        for(int i=-1;i<leftlen-1;i++)
        {
            string modleft;
            if(i==-1) 
            {
                if(valid(leftstr)) modleft=leftstr;
                else continue;
            }
            else 
            {
                modleft= leftstr.substr(0,i+1) + '.' + leftstr.substr(i+1,leftstr.size()-i-1);
                if(!valid(modleft)) continue;
            }
            for(int j=-1;j<rightlen-1;j++)
            {
                string modright;
                if(j==-1)
                {
                    if(valid(rightstr)) modright=rightstr;
                    else continue;
                }
                else
                {
                    modright=rightstr.substr(0,j+1) + '.' + rightstr.substr(j+1,rightstr.size()-j-1);
                    if(!valid(modright))  continue;
                }
                ans.push_back("(" + modleft + ", " + modright + ")");
            }
        }
        return;
    }
    vector<string> ambiguousCoordinates(string s) {
        s = s.substr(1, s.size() - 2);
        for(int i=0;i<s.size()-1;i++)
        {
            string leftstr= s.substr(0,i+1);
            string rightstr= s.substr(i+1,s.size()-i-1);
            helper(leftstr,rightstr);
        }
        return ans;
    }
};
