class Solution {
public:
    vector<int> ans;
    bool isop(char c)
    {
        if(c=='+' || c=='-' || c=='*')
        {
          return true;
        }
        return false;
    }
    int eval(char op,int l,int r)
    {
        if(op=='+') return l+r;
        else if(op=='-') return l-r;
        else if(op=='*') return l*r;
        return 0;
    }
    vector<int> backtracking(string& expression,int l,int r)
    {
        vector<int> res;
        for(int i=l;i<=r;i++)
        {
            if(isop(expression[i]))
            {
                int oper= expression[i];
                vector<int> la= backtracking(expression,l,i-1);
                vector<int> ra= backtracking(expression,i+1,r);
                for(int j=0;j<la.size();j++)
                {
                    for(int k=0;k<ra.size();k++)
                    {
                        res.push_back(eval(oper,la[j],ra[k]));
                    }
                }
            }
        }
        if(res.empty())
        {
            res.push_back(stoi(expression.substr(l,r-l+1)));
        }
        return res;
    }
    vector<int> diffWaysToCompute(string expression) {
        return backtracking(expression,0,expression.size()-1);
    }
};
