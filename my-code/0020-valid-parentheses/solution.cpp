class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(!st.empty())
            {
              if(st.top()=='(' && s[i]==')')
              {
                st.pop();
                continue;
              } 
              else if(st.top()=='{' && s[i]=='}')
              {
                st.pop();
                continue;
              } 
              else if(st.top()=='[' && s[i]==']')
              {
                st.pop();
                continue;
              }
            }
            st.push(s[i]);
        }
        if(st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
