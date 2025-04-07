class Solution {
public:
    int romanToInt(string s) {
        map <char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int n=0;
        for(int i=0;i<s.size();i++)
        {
            if(i!=s.size()-1)
        {
          char c1=s[i];
          char c2=s[i+1];
          if(s[i]=='I' && s[i+1]=='V')
          {
            n=n+4;
            i=i+1;
            continue;
          }
          else if(s[i]=='I' && s[i+1]=='X')
          {
            n=n+9;
            i=i+1;
            continue;
          }
          else if(s[i]=='X' && s[i+1]=='L')
          {
            n=n+40;
            i=i+1;
            continue;
          }
          else if(s[i]=='C' && s[i+1]=='D')
          {
            n=n+400;
            i=i+1;
            continue;
          }
          else if(s[i]=='X' && s[i+1]=='C')
          {
            n=n+90;
            i=i+1;
            continue;
          }
          else if(s[i]=='C' && s[i+1]=='M')
          {
            n=n+900;
            i=i+1;
            continue;
          }
          else
          {
            n=n+m[s[i]];
            continue;
          }
        }
     else
     {
        n=n+m[s[i]];
     }
        }
        return n;
       }
    };
