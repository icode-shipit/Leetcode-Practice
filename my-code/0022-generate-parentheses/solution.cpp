class Solution {
public:
    unordered_map<char,int> m;
    vector<string> ans;
    string temp;
    int open=0;
    int closed=0;
    void backtracking(int n)
    {
        if(open<closed)
        {
            return;
        }
        if(temp.size()==n*2)
        {
            ans.push_back(temp);
            return;
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second>0)
            {
                if(it->first=='(')
                {
                    open++;
                }
                else
                {
                    closed++;
                }
                temp.push_back(it->first);
                it->second--;
                backtracking(n);
                temp.pop_back();
                if(it->first=='(')
                {
                    open--;
                }
                else
                {
                    closed--;
                }
                it->second++;
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        m['(']=n;
        m[')']=n;
        backtracking(n);
        return ans;
    }
};
