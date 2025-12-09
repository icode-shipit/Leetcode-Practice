class Solution {
public:
    bool isPalindrome(string s) {
        int i1=0;
        int i2=s.size()-1;
        while(i1<i2)
        {
           if( isalpha(s[i1]) && isalpha(s[i2]) ) 
           {
            if( tolower(s[i1]) != tolower(s[i2]) )
            {
                return false;
            }
           i1++;
           i2--;
           }
           else if(isdigit(s[i1]) && isdigit(s[i2]) )
           {
            if(s[i1]!=s[i2])
            {
                return false;
            }
           i1++;
           i2--;
           }
           else if(!isalnum(s[i1]) && !isalnum(s[i2]))
           {
            i1++;
            i2--;
           }
           else if(!isalnum(s[i1]))
           {
            i1++;
           }
           else if(!isalnum(s[i2]))
           {
            i2--;
           }
           else
           {
            return false;
           }
        }
        return true;
    }
};
